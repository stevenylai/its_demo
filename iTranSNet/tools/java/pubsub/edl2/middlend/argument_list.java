package pubsub.edl2.middlend;

import java.util.*;

public class argument_list extends GenericTreeNode {
	public argument_list() {
		createChildren();
	}
	/*public Vector staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		Vector paralist = new Vector();
		for (int i=0; i<children.size(); i++) {
			argument a = (argument)children.get(i);
			String expr_type = a.staticTypeCheck (t);
			if (expr_type!=null) {
				MethodParameter mp = new MethodParameter();
				mp.setType(expr_type);
				paralist.add(mp);
			} else {
				throw new TypeException("Parameter type error");
			}
		}
		return paralist;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		for (int i=0; i<children.size(); i++) {
			argument a = (argument)children.get(i);
			a.generateCode (t, codes);
			codes.addInstruction("2fillcalleeparameter8 "+i);
		}
	}*/
	public String getName () {
		return "Nonterminal: argument_list";
	}
}
