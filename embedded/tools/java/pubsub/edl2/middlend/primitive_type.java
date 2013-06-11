package pubsub.edl2.middlend;
import java.util.*;

public class primitive_type extends GenericTreeNode {
	String type_id;
	public primitive_type() {
		createChildren();
	}
	public primitive_type(String type) {
		this();
		type_id=type;
	}
	public String toString () {
		return type_id;
	}
	public String getName () {
		return "Nonterminal: primitive_type "+type_id;
	}
}
