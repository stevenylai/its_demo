package pubsub.edl2.middlend;


import java.util.*;

public class field_declarations extends GenericTreeNode {
	public field_declarations() {
		createChildren();
	}
	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException {
		for (int i=0; i<children.size(); i++) {
			Object candidate = children.get(i);
			if (candidate instanceof field_declaration) {
				field_declaration fd = (field_declaration)candidate;
				fd.constructTable(t);
			}
		} // end of 'for'
	}*/
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		for (int i=0; i<children.size(); i++) {
			Object candidate = children.get(i);
			if (candidate instanceof field_declaration) {
				field_declaration fd = (field_declaration)candidate;
				fd.staticTypeCheck(t);
			}
		} // end of 'for'
		return null;
	}
	public void generateCode (SymbolTable t, ClassCode codes) throws UndefinedSymbolException,TypeException {
		for (int i=0; i<children.size(); i++) {
			Object candidate = children.get(i);
			if (candidate instanceof field_declaration) {
				field_declaration fd = (field_declaration)candidate;
				fd.generateCode(t, codes);
			}
		} // end of 'for'
	}*/
	public String getName () {
		return "Nonterminal: field_declarations";
	}
}
