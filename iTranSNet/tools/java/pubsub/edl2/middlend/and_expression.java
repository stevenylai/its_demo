package pubsub.edl2.middlend;


import java.util.*;

public class and_expression extends expression {
	String oper;
	public and_expression() {
		createChildren();
	}
	public and_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: and_expression";
		else
			return "Nonterminal: and_expression "+oper;
	}
	/*
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		expression e1 = (expression)children.get(0);
		expression e2 = (expression)children.get(1);
		e1.generateCode(t, codes);
		e2.generateCode(t, codes);
		codes.addInstruction("and");
	}*/
}
