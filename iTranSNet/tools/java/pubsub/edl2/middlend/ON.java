package pubsub.edl2.middlend;
import java.util.*;

public class ON extends GenericTreeNode {
	String oper;
	public ON() {
		createChildren();
	}
	public ON (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Terminal: ON";
		else
			return "Terminal: ON "+oper;
	}
}
