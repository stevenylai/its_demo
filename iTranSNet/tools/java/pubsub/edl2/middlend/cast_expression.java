package pubsub.edl2.middlend;


import java.util.*;

public class cast_expression extends expression {
	String oper;
	public cast_expression() {
		createChildren();
	}
	public cast_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: cast_expression";
		else
			return "Nonterminal: cast_expression "+oper;
	}
	/*
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
	}*/
}
