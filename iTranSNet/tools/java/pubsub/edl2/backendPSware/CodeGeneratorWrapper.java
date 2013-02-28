package pubsub.edl2.backendPSware;

import java.util.*;
import java.io.*;
import java.util.regex.*;
import pubsub.edl2.middlend.*;
import pubsub.edl2.symbols.*;

public class CodeGeneratorWrapper {
	public CodeRepository codes;
	/*public Vector assemble() throws IOException{
		Vector program=codes.getAllInstructions();
		Assembler assembler = new Assembler();
		Vector packets = assembler.assembleProgram(program);
		return packets;
	}*/
	public void generateMetaData(GenericTreeNode root, SymbolTable table) {
		
	}
	public void generateCode(GenericTreeNode root, SymbolTable table) {
		codes = new CodeRepository();
		try {
			System.out.println("Code generation...");
			CodeGenerator cg = new CodeGenerator();
			cg.generateCode(root, table, codes);
			codes.printCodes(0);
			System.out.println(codes.getFilterCodes());
			/*
			Vector program=codes.getAllInstructions();
			for (int i=0; i<program.size(); i++)
				System.out.println((String)program.get(i));*/

		} catch (Exception e) {
			e.printStackTrace();
		}
	} // end of generateCode
}

