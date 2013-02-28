package pubsub.edl2.middlend;


import java.util.*;

public class field_declaration extends class_body_declaration {
	public field_declaration() {
		createChildren();
	}

	public String getType () {
		Object child1 = children.get(0); // type
		String typeStr="";
		if (child1 instanceof primitive_type) {
			primitive_type pt = (primitive_type)child1;
			typeStr = pt.toString();
		} else if (child1 instanceof name) {
			name nm = (name)child1;
			typeStr = nm.getFullName();
		} else if (child1 instanceof Identifier) {
			Identifier id = (Identifier)child1;
			typeStr = id.toString();
		}
		return typeStr;
	}
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		variable_declarators vd = (variable_declarators)children.get(1); // list of variables
		return vd.staticTypeCheck(t);
	}
	public void generateCode (SymbolTable t, ClassCode codes) throws UndefinedSymbolException,TypeException {
		variable_declarators vd = (variable_declarators)children.get(1); // list of variables
		vd.generateCode (t, codes);
	}*/
	public String getName () {
		return "Nonterminal: field_declaration";
	}
}
