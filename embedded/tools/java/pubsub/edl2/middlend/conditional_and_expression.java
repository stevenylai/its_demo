package pubsub.edl2.middlend;


import java.util.*;

public class conditional_and_expression extends expression {
	String oper;
	public conditional_and_expression() {
		createChildren();
	}
	public conditional_and_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: conditional_and_expression";
		else
			return "Nonterminal: conditional_and_expression "+oper;
	}
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		expression e1 = (expression)children.get(0);
		expression e2 = (expression)children.get(1);
		String type1 = e1.staticTypeCheck (t);
		String type2 = e2.staticTypeCheck (t);
		if (!TypeInfo.typeMatch(type1,type2)) {
			throw new TypeException ("Type mismatch of "+type1+" and "+type2);
		} else if (!TypeInfo.typeMatch(type1,"boolean")) {
			throw new TypeException ("Type error of type: "+type1+", expected: boolean");
		} else
			return type1;
	}
*/
}
