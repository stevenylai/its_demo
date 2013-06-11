package pubsub.edl2.middlend;


import java.util.*;

public class variable_declarator extends GenericTreeNode {
	public variable_declarator() {
		createChildren();
	}
	public String getID () {
		Identifier id = (Identifier)children.get(0);
		return id.toString();
	}
	/*public String staticTypeCheck (SymbolTable t, String targetType) throws UndefinedSymbolException, UndefinedSymbolException, TypeException {
		if (children.size()>1) {
			expression e = (expression)children.get(1);
			String realType = e.staticTypeCheck(t);
			if (realType==null) {
				throw new TypeException ("Undefined type error");
			} else if (!realType.equals(targetType)) {
				throw new TypeException ("Type mismatch for type: "+realType+", expected: "+targetType);
			}
		}
		return targetType;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		if (children.size()>1) {
			expression e = (expression)children.get(1);
			e.generateCode(t, codes);
		}
		Variable v = (Variable)t.lookUp(new Variable(getID()));
		if (v!=null) {
			codes.addInstruction(v.setInstruction());
		} else
			throw new UndefinedSymbolException (new Variable(getID()));
	}*/
	public String getName () {
		return "Nonterminal: variable_declarator";
	}
	public void adjust () {
		int i=0;
		while (i<children.size()) {
			Object child = children.get(i);
			if (child!=null && child instanceof variable_declarator) {
				parent.addChild((GenericTreeNode)children.remove(i));
			}
			else
				i++;
		}
		super.adjust();
	}
}
