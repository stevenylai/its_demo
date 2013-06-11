package pubsub.edl2.middlend;


import java.util.*;

public class additive_expression extends expression {
	public String oper;
	public additive_expression() {
		createChildren();
	}
	public additive_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: additive_expression";
		else
			return "Nonterminal: additive_expression "+oper;
	}
}
