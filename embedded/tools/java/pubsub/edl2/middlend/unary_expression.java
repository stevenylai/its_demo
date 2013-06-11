package pubsub.edl2.middlend;


import java.util.*;

public class unary_expression extends expression {
	String oper;
	public unary_expression() {
		createChildren();
	}
	public unary_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: unary_expression";
		else
			return "Nonterminal: unary_expression "+oper;
	}
	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException {
		expression e1 = (expression)children.get(0);
		e1.constructTable(t);
	}*/
	/*public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		expression e1 = (expression)children.get(0);
		if (oper.equals("-")) {
			codes.addInstruction("2pushc10 0");
			e1.generateCode(t, codes);
			codes.addInstruction("sub");
		}
	}*/
}
