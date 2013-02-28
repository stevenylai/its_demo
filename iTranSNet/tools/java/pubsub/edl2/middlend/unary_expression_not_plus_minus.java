package pubsub.edl2.middlend;


import java.util.*;

public class unary_expression_not_plus_minus extends expression {
	String oper;
	public unary_expression_not_plus_minus() {
		createChildren();
	}
	public unary_expression_not_plus_minus (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: unary_expression_not_plus_minus";
		else
			return "Nonterminal: unary_expression_not_plus_minus "+oper;
	}
	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException {
		expression e1 = (expression)children.get(0);
		e1.constructTable(t);
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		expression e1 = (expression)children.get(0);
		e1.generateCode(t, codes);
		if (oper.equals("!")) {
			codes.addInstruction("not");
		}
	}*/
}
