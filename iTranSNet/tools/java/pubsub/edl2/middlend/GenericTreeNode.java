package pubsub.edl2.middlend;


import java.util.*;

public class GenericTreeNode {
	public Vector children;
	private int visitCount;
	protected GenericTreeNode parent;

	protected Hashtable inheritAttributes;
	protected Hashtable normalAttributes;

	public GenericTreeNode () {
		inheritAttributes = new Hashtable();
		normalAttributes = new Hashtable();
		createChildren();
	}
	protected void createChildren () {
		children = new Vector();
		visitCount = 0;
	}
	public Vector getChildren () { return children; }
	public GenericTreeNode getNextChildren () {
		GenericTreeNode n = null;
		if (visitCount<children.size())
			n = (GenericTreeNode)children.get(visitCount++);
		return n;
	}
	//public void setInheritAttributes (Hashtable inheritAttributes) { this.inheritAttributes=inheritAttributes; }
	public Hashtable getInheritAttributes () { return this.inheritAttributes; }
	public void removeInheritAttribute (Object key) {
		inheritAttributes.remove(key);
	}
	public void addInheritAttribute (Object key, Object value) {
		inheritAttributes.put(key, value);
		copyInheritAttributes();
	}
	public Object getInheritAttribute (Object key) {
		return inheritAttributes.get(key);
	}

	public void removeNormalAttribute (Object key) {
		normalAttributes.remove(key);
	}
	public void addNormalAttribute (Object key, Object value) {
		normalAttributes.put(key, value);
	}
	public Object getNormalAttribute (Object key) {
		return normalAttributes.get(key);
	}

	public void addChild (GenericTreeNode n) {
		children.add(n);
		if (n!=null) {
			n.setParent(this);
		}
	}
	public void setParent (GenericTreeNode n) {
		parent = n;
		//System.out.println("I am "+getName()+" my parent is "+parent.getName());
	}
	public GenericTreeNode getParent () { return this.parent; }
	public String getName () {
		return "GenericTreeNode";
	}
	public void traverse(int level) {
		for (int i=0; i<level; i++)
			System.out.print(" ");
		System.out.println(getName());

		/*
		System.out.print(getName());
		if (getInheritAttribute("walkthrough_statement")!=null) {
			walkthrough_statement ws =(walkthrough_statement)getInheritAttribute("walkthrough_statement");
			if (ws!=null) {
				System.out.print(" with walkthrough attribute: "+ws);
			}
		}
		System.out.println("");*/

		for (int i=0; i<children.size(); i++) {
			GenericTreeNode np = (GenericTreeNode)children.get(i);
			if (np!=null)
				np.traverse(level+1);
		}
	}
	public void adjust () {
		copyInheritAttributes();
	}
	public void copyInheritAttributes () {
		for (int i=0; i<children.size(); i++) {
			GenericTreeNode np = (GenericTreeNode)children.get(i);
			if (np!=null) {
				np.getInheritAttributes().putAll(this.inheritAttributes);
				np.adjust();
			}
		}
	}
}
