package pubsub.edl2.middlend;

import java.util.*;

public class subscribe_statement extends statement {
	public subscribe_statement() {
		createChildren();
	}
	public String getName () {
		return "Nonterminal: subscribe_statement";
	}
	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException	{
		return;
	}
	public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		class_instance_creation_expression cice = (class_instance_creation_expression)children.get(0);
		String class_name = cice.staticTypeCheck(t);
		sub_event = (ClassEntry)t.lookUp(new ClassEntry(class_name));
		sub_event.setSubscribed(true);
		return class_name;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		//codes.addInstruction();
		codes.addLabel("main");
		codes.addInstruction("clear");
		class_instance_creation_expression cice = (class_instance_creation_expression)children.get(0);
		cice.generateCode(t, codes);
		ClassMethod cm = findOccurred(sub_event);
		if (cm!=null) {
			// FIXME: ugly hacks here. The correct way to do this is to use a preprocessor to generate some codes first
			codes.addInstruction("2createparameter8 "+cm.getParameterSize());
			codes.addInstruction("createreturn");
			codes.addInstruction("2createlocal8 "+cm.getLocalSize());
			codes.addInstruction("2setcalleelocal8 "+THIS.this_address);
			codes.addInstruction("pop");
			codes.addInstruction("2call8 "+cm.getLabel());
		} else
			throw new TypeException("Subscribed event has no occurred method.");
		codes.addInstruction("halt");
	}
	public ClassMethod findOccurred(ClassEntry ce) {
		Vector methods = ce.getMethods();
		for (int i=0; i<methods.size(); i++) {
			ClassMethod cm = (ClassMethod)methods.get(i);
			if (cm.getID().equals("occurred")) // FIXME: need to check type as well.
				return cm;
		}
		return null;
	}*/
}
