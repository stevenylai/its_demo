package pubsub.edl2.middlend;

import java.util.*;

public class argument extends GenericTreeNode {
	public argument() {
		createChildren();
	}
	/*
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		expression e = (expression)children.get(0);
		e.generateCode (t, codes);
	}*/
	public String getName () {
		return "Nonterminal: argument";
	}
	public void adjust () {
		int i=0;
		while (i<children.size()) {
			Object child = children.get(i);
			if (child!=null && child instanceof argument) {
				parent.addChild((GenericTreeNode)children.remove(i));
			}
			else
				i++;
		}
		super.adjust();
	}
}
