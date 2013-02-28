package pubsub.edl2.middlend;

import java.util.*;

public class Identifier extends expression {
	String identifier;
	public Identifier(String identifier) { this(); this.identifier=identifier; }
	public Identifier() {
		createChildren();
	}
	public String getName () {
		return "Identifier: "+identifier;
	}
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		// Resolve as variable
		Variable v = (Variable)t.lookUp(new Variable(this.identifier));
		if (v!=null)
			return v.getType();
		else { // resolve as class:
			ClassEntry ce = (ClassEntry)t.lookUp(new ClassEntry(this.identifier));
			if (ce!=null)
				return ce.getID();
		}
		return null;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
	}
	public void generateRightValueCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		generateCode(t, codes);
	}
	public void generateLeftValueCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		System.out.println("Inappropriate use of expression as left value");
	}*/
	public String toString () {
		return identifier;
	}
	public void adjust () {
		int i=0;
		while (i<children.size()) {
			Object child = children.get(i);
			if (child!=null && child instanceof Identifier) {
				parent.addChild((GenericTreeNode)children.remove(i));
			}
			else
				i++;
		}
		super.adjust();
	}
}
