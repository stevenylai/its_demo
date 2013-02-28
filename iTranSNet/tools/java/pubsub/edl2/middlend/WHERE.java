package pubsub.edl2.middlend;
import java.util.*;

public class WHERE extends GenericTreeNode {
	String oper;
	public WHERE() {
		createChildren();
	}
	public WHERE (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Terminal: WHERE";
		else
			return "Terminal: WHERE "+oper;
	}
}
