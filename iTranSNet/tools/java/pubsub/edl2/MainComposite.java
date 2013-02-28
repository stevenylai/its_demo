package pubsub.edl2;

import java.util.*;
import java.io.*;
import java.util.regex.*;
import pubsub.edl2.frontendComposite.*;
import pubsub.edl2.symbols.*;
import pubsub.edl2.middlend.*;
import pubsub.edl2.backendPSware.*;
import pubsub.edl2.receiver.*;
import pubsub.edl2.receiver.notifier.*;
import vm_specific.*;
// TinyOS related
import net.tinyos.util.*;
import net.tinyos.message.*;

public class MainComposite{
	static MoteIF mote;
	public static short version=0;
	static {
		mote=new MoteIF();
		version=1;
	}

	// Configuration stuff
	private String constantClassName;
	private ConstantMapper capsuleMap;
	private ConstantMapper optionMap;
	private ConstantMapper errorMap;
	private ConstantMapper opcodeMap;
	private ConstantMapper virusMap;
	private ConstantMapper eventMap;
	public EventReceiver receiver;
	public MainComposite () {
		constantClassName="vm_specific.MateConstants";
		capsuleMap = new ConstantMapper(constantClassName, "MATE_CAPSULE_");
		optionMap = new ConstantMapper(constantClassName, "MATE_OPTION_");
		errorMap = new ConstantMapper(constantClassName, "MATE_ERROR_");
		opcodeMap = new ConstantMapper(constantClassName, "OP");
		virusMap = new ConstantMapper(constantClassName, "MVIRUS_");
		eventMap = new ConstantMapper(constantClassName, "EVENT_");
		resetSettings();
	}
	public void resetSettings() {
		ClassEntry.subscribeIDcount=0;
	}
	private void sendEventMeta(CodeGeneratorWrapper cg) {
		try {
			for (int i=0; i<cg.codes.meta.size(); i++) {
				EventMetaInfo m = cg.codes.meta.get(i);
				EventMetaMsg msg = new EventMetaMsg();
				msg.set_type(EventMetaInfo.EVENT_META_UPDATE);
				msg.set_eventType(m.type);
				msg.set_subID(m.subID);
				msg.set_lifetime(m.lifetime);
				msg.set_rate(m.rate);
				msg.set_length(m.length);
				System.out.println(msg);
				//for (int j=0; j<1; j++) {
					mote.send(MoteIF.TOS_BCAST_ADDR, msg);
					Thread.sleep(1000);
				//}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public byte [] assembleProgram (String instructions) throws IOException {
		byte[] code;

		System.out.println("Assembling ...");
		System.out.println(instructions);
		ScriptAssembler assembler = new ScriptAssembler(opcodeMap);
		StringReader prog_reader = new StringReader(instructions);
		AssemblyTokenizer tokenizer = new AssemblyTokenizer(prog_reader);
		String program = assembler.toHexString(tokenizer);
		System.out.println(program);

		prog_reader = new StringReader(instructions);
		tokenizer = new AssemblyTokenizer(prog_reader);
		code = assembler.toByteCodes(tokenizer);

		return code;
	}
	public void sendProgram (byte code[], int capsuleID) throws IOException {
		CapsuleMsg msg = new CapsuleMsg();
		byte num;
		byte type;
		byte version;
		num = (byte)capsuleID; // Which Capsule/Context
		//type = (byte)(num | (byte)0x80);
		type = (byte)num;
		msg.set_capsule_type(type);
		version = (byte)MainComposite.version++;
		//msg.set_capsule_version((char)(version & 0xffffffff));
		msg.set_capsule_version(version);
		byte[] sCode = new byte[code.length];
		for (int i = 0; i < code.length; i++) {
			sCode[i] = code[i];
		}
		msg.set_capsule_code(sCode);
		msg.set_capsule_codeLen(code.length);

		// Chunk it up and send those out
		int chunkSize = virusMap.nameToCode("CHUNK_SIZE");
		byte[] capsule = msg.dataGet();
		int capsuleHeaderSize = 8;
		int numChunks = (sCode.length + capsuleHeaderSize + chunkSize - 1) / chunkSize;
		System.err.print("Sending " + numChunks + " chunks (" + sCode.length + "," + chunkSize + "): ");
		for (byte i = 0; i < numChunks; i++) {
			CapsuleChunkMsg chunk = new CapsuleChunkMsg();
			chunk.set_version(version);
			chunk.set_capsuleNum(num);
			chunk.set_piece(i);
			short[] chunkData = new short[chunkSize];
			for (int j = 0; j < chunkSize; j++) {
				chunkData[j] = capsule[i * chunkSize + j];
			}
			chunk.set_chunk(chunkData);
			int moteID = MoteIF.TOS_BCAST_ADDR;
			System.out.println(chunk);
			mote.send(moteID, chunk);
			System.out.print("+");
			try {
				Thread.sleep(2000);
			} catch (Exception e) {}
		}
		System.out.println();
	}
	public void dissemination(CodeGeneratorWrapper cg) throws IOException {
		// Meta
		sendEventMeta(cg);
		// Filters
		String toAssembler=cg.codes.getFilterCodes();
		byte [] bytCodes = assembleProgram(toAssembler);
		sendProgram(bytCodes, capsuleMap.nameToCode("TIMER0"));
	}
	public void initEventReceiver(CodeGeneratorWrapper cg) throws IOException {
		mote.registerListener(new EventInstanceMsg(), receiver);
		Vector <String> codes = cg.codes.getAllInstructions();
		receiver.codes = codes;
		receiver.meta.clear();
		for (int i=0; i<cg.codes.meta.size(); i++) {
			EventMetaInfo em = cg.codes.meta.get(i);
			receiver.meta.add(em);
			//System.out.println("Added meta: "+cg.codes.meta.get(i).toString());
		}
		//receiver.notifiers.add(new DummyNotifier());
	}
	public void compile(Reader reader) {
		try {
			ParserWrapper p = new ParserWrapper();
			p.parse(reader);
			CodeGeneratorWrapper cg = new CodeGeneratorWrapper();
			cg.generateCode(p.getRoot(), p.getTable());
			
			dissemination(cg);

			if (receiver==null) {
				receiver = new EventReceiver();
				Thread vm_thread = new Thread(receiver);
				vm_thread.start();
			}
			initEventReceiver(cg);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) throws IOException, UndefinedSymbolException, TypeException {
		MainComposite m = new MainComposite();
		m.compile(new InputStreamReader(System.in));
	}
}
