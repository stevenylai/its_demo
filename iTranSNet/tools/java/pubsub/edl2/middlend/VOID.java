package pubsub.edl2.middlend;
import java.util.*;

public class VOID extends GenericTreeNode {
	public VOID() {
		createChildren();
	}
	public String toString () {
		return "VOID";
	}
	public String getName () {
		return "Nonterminal: VOID";
	}
}
