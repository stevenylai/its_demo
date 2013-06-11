package pubsub.edl2.middlend;


import java.util.*;

public class conditional_or_expression extends expression {
	String oper;
	public conditional_or_expression() {
		createChildren();
	}
	public conditional_or_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: conditional_or_expression";
		else
			return "Nonterminal: conditional_or_expression "+oper;
	}
}
