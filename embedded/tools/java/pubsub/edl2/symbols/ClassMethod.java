package pubsub.edl2.symbols;

import java.io.*;
import java.util.*;

public class ClassMethod extends AbstractSymbol {
	private Vector modifiers;
	private String type;
	private String id;
	private Vector parameters;

	private Vector localVariables;
	private int variableIndex;

	public ClassMethod () {
		super();
		variableIndex = 1; // 0 and 1 are reserved
	}
	public ClassMethod (String id) {
		this();
		this.id=id;
	}
	public void typeCheck () {
		// FIXME: need to type check all of the variables in all of the blocks of the method
	}

	public void setType (String type) { this.type=type; }
	public void setID (String id) { this.id=id; }
	public void setModifiers (Vector modifiers) { this.modifiers=modifiers; }
	public void setParameters (Vector parameters) { this.parameters=parameters; }
	public void generateKey () { setKey("method_"+toString()); }

	public String getType () { return this.type; }
	public String getID () { return this.id; }
	public Vector getParameters () { return this.parameters; }
	public Vector getModifiers () { return this.modifiers; }
	// FIXME: label needs to be unique AND contains only alphanumeric
	public String getLabel () {
		SymbolTable parent_table = getParentTable();
		ClassEntry ce = (ClassEntry)parent_table.getParentSymbol();
		return "label_method_"+ce.toString()+"_"+id; }
	public int getLocalSize () { return variableIndex; }
	public int getParameterSize () throws UndefinedSymbolException {
		int totalsize=0;
		if (parameters==null)
			return 0;
		for (int i=0; i<parameters.size(); i++) {
			MethodParameter mp = (MethodParameter)parameters.get(i);
			totalsize+=mp.getLength();
		}
		return totalsize;
	}

	// FIXME: the type of the variable may be unknown at this point.
	public void addVariable (Variable v) {
		if (v instanceof MethodParameter) {
		} else {
			v.setIndex (variableIndex++);
		}
	}
	public boolean isStatic() {
		for (int i=0; i<modifiers.size(); i++) {
			String mod = (String)modifiers.get(i);
			if (mod.equals("static"))
				return true;
		}
		return false;
	}

	public String printParameterTypes () {
		String paralist="";
		if (parameters!=null && parameters.size()>0) {
			for (int i=0; i<parameters.size(); i++) {
				paralist=paralist+((MethodParameter)parameters.get(i)).getType()+" ";
			}
		}
		return paralist;
	}
	public String toString () {
		return this.id+"( "+printParameterTypes()+")";
	}
}
