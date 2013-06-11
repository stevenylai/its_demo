package pubsub.edl2.middlend;


import java.util.*;

public class equality_expression extends expression {
	public String oper;
	public equality_expression() {
		createChildren();
	}
	public equality_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: equality_expression";
		else
			return "Nonterminal: equality_expression "+oper;
	}
}
