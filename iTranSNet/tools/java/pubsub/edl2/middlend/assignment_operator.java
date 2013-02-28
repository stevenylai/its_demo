package pubsub.edl2.middlend;
import java.util.*;

public class assignment_operator extends GenericTreeNode {
	String oper;
	public assignment_operator() {
		createChildren();
	}
	public assignment_operator(String oper) {
		this();this.oper=oper;
	}
	public String getName () {
		return "Nonterminal: assignment_operator "+oper;
	}
}
