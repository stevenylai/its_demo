package pubsub.edl2.middlend;
import java.util.*;

public class class_type extends GenericTreeNode {
	public class_type() {
		createChildren();
	}
	public String getFullClassName() {
		name child1 = (name)children.get(0);
		return child1.getFullName();
	}
	public String getName () {
		return "Nonterminal: class_type";
	}
}
