package pubsub.edl2.middlend;
import java.util.*;

public class class_body_declaration extends GenericTreeNode {
	public class_body_declaration() {
		createChildren();
	}
	public String getName () {
		return "Nonterminal: class_body_declaration";
	}
	public void adjust () {
		int i=0;
		while (i<children.size()) {
			Object child = children.get(i);
			if (child!=null && child instanceof class_body_declaration) {
				parent.addChild((GenericTreeNode)children.remove(i));
			}
			else
				i++;
		}
		super.adjust();
	}
}
