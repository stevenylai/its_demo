package pubsub.edl2.middlend;


import java.util.*;

public class goal extends GenericTreeNode {
	public goal() {
		//System.out.println (getName() + " created");
		createChildren();
	}
	/*public String staticTypeCheck (SymbolTable table) throws UndefinedSymbolException, TypeException {
		for (int i=0; i<children.size(); i++) {
			Object child = children.get(i);
			if (child instanceof event_declaration ) {
				event_declaration cd = (event_declaration)child;
				cd.staticTypeCheck(table);
			} else if (child instanceof subscribe_statement) {
				subscribe_statement ss = (subscribe_statement)child;
				ss.staticTypeCheck(table);
			}
		}
		return null;
	}
	public void generateCode (SymbolTable table, CodeRepository codes) throws UndefinedSymbolException,TypeException {   
		for (int i=0; i<children.size(); i++) {
			Object child = children.get(i);
			if (child instanceof event_declaration ) {
				event_declaration cd = (event_declaration)child;
				cd.generateCode(table, codes);
			} else if (child instanceof subscribe_statement) {
				subscribe_statement ss = (subscribe_statement)child;
				ss.generateCode(table, codes.getMainCode());
			}
		}
	}*/
	public String getName () {
		return "Nonterminal: goal";
	}
}
