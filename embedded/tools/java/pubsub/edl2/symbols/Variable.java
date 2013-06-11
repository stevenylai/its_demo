package pubsub.edl2.symbols;

import java.io.*;
import java.util.*;

public class Variable extends AbstractSymbol implements Cloneable {
	private String type;
	private String id;
	private int idx;

	private Vector composite_read;
	private Vector composite_write;

	public Variable () {
		super();
		composite_read = new Vector();
		composite_write = new Vector();
	}
	public Variable(String id) {
		this();
		this.id=id;
		setKey("variable_"+id);
	}

	public void generateKey () {
		setKey("variable_"+id);
	}
	public void typeCheck () {
		AbstractSymbol as = getParentTable().lookUp(new ClassEntry(type));
		if (as instanceof ClassEntry) {
			ClassEntry ce = (ClassEntry)as;
			setSymbolTable(ce.getTable());
		} else if (!isPrimitiveType()) {
			System.out.println("Undefined class: "+type);
		}
	}
	public boolean isPrimitiveType() {
		// FIXME: more types need to be supported
		return type.equals("int")||type.equals("boolean");
	}
	public void setID (String id) { this.id=id; }
	public void setIndex (int idx) { this.idx=idx; }
	public void setType (String type) { this.type=type; }
	public void setSharedWrite (int composite_id, int composite_offset) {
		int [] composite_info = { composite_id, composite_offset };
		for (int i=0; i<composite_write.size(); i++) {
			int [] tmp_info = (int [])composite_write.get(i);
			if (tmp_info[0]==composite_info[0]) {
				composite_write.set(i, composite_info);
				return;
			}
		}
		composite_write.add(composite_info);
	}
	public void setSharedRead (int composite_id, int composite_offset) {
		int [] composite_info = { composite_id, composite_offset };
		for (int i=0; i<composite_read.size(); i++) {
			int [] tmp_info = (int [])composite_read.get(i);
			if (tmp_info[0]==composite_info[0]) {
				composite_read.set(i, composite_info);
				return;
			}
		}
		composite_read.add(composite_info);
	}
	public void removeSharedRead  (int composite_id) {
		for (int i=0; i<composite_read.size(); i++) {
			int [] tmp_info = (int [])composite_read.get(i);
			if (tmp_info[0]==composite_id)
				composite_read.remove(i);
		}
	}
	/*public void generateCompositeInstructions (CodeStore codes, int offset) throws UndefinedSymbolException {
		for (int i=0; i<composite_read.size(); i++) {
			int [] tmp_info = (int [])composite_read.get(i);
			if (isPrimitiveType()) {
				codes.addInstruction("2pushc10 "+(tmp_info[1]+offset));
				codes.addInstruction("2setsharedread8 "+tmp_info[0]);
			} else {
				codes.addInstruction("2pushc10 "+tmp_info[1]);
				codes.addInstruction("2pushc10 "+getLength());
				codes.addInstruction("2copyread8 "+tmp_info[0]);
			}
		}
		for (int i=0; i<composite_write.size(); i++) {
			int [] tmp_info = (int [])composite_write.get(i);
			if (isPrimitiveType()) {
				codes.addInstruction("2pushc10 "+(tmp_info[1]+offset));
				codes.addInstruction("2setsharedwrite8 "+tmp_info[0]);
			} else {
				codes.addInstruction("2pushc10 "+tmp_info[1]);
				codes.addInstruction("2pushc10 "+getLength());
				codes.addInstruction("2copywrite8 "+tmp_info[0]);
			}
		}
	}*/

	public String getID () { return this.id; }
	public int getIndex () { return this.idx; }
	public String getType () { return this.type; }
	public boolean isSharedRead () { return composite_read.size()>0; }
	public boolean isSharedWrite () { return composite_write.size()>0; }

	public int getLength () throws UndefinedSymbolException {
		if (isPrimitiveType())
			return 1;
		else {
			ClassEntry ce = (ClassEntry)getParentTable().lookUp(new ClassEntry(type));
			if (ce!=null) 
				return ce.getAllocateSize();
			else
				throw new UndefinedSymbolException (new ClassEntry(type));
		}
	}
	public void setCompositeInstruction (int composite_id, Vector instructions) throws UndefinedSymbolException {
		setCompositeInstruction(composite_id, instructions, getLength(), 0);
	}
	public void setCompositeInstruction (int composite_id, Vector instructions, int length, int offset) {
		for (int i=0; i<composite_read.size(); i++) {
			int [] tmp_info = (int [])composite_read.get(i);
			if (tmp_info[0]==composite_id) {
				instructions.add("2pushc10 "+(tmp_info[1]+offset));
				instructions.add("2pushc10 "+length);
				instructions.add("2copyread8 "+tmp_info[0]);
			}
		}
		for (int i=0; i<composite_write.size(); i++) {
			int [] tmp_info = (int [])composite_write.get(i);
			if (tmp_info[0]==composite_id) {
				instructions.add("2pushc10 "+(tmp_info[1]+offset));
				instructions.add("2pushc10 "+length);
				instructions.add("2copywrite8 "+tmp_info[0]);
			}
		}
	}
	public void getCompositeInstruction (int composite_id, Vector instructions) {
		getCompositeInstruction (composite_id, instructions, 0);
	}
	public void getCompositeInstruction (int composite_id, Vector instructions, int offset) {
		for (int i=0; i<composite_read.size(); i++) {
			int [] tmp_info = (int [])composite_read.get(i);
			if (tmp_info[0]==composite_id) {
				instructions.add("2pushc10 "+(tmp_info[1]+offset));
				if (isPrimitiveType())
					instructions.add("2getsharedread8 "+tmp_info[0]);
				else
					instructions.add("2getreadaddress8 "+tmp_info[0]);
			}
		}
		for (int i=0; i<composite_write.size(); i++) {
			int [] tmp_info = (int [])composite_write.get(i);
			if (tmp_info[0]==composite_id) {
				instructions.add("2pushc10 "+(tmp_info[1]+offset));
				if (isPrimitiveType())
					instructions.add("2getsharedwrite8 "+tmp_info[0]);
				else
					instructions.add("2getwriteaddress8 "+tmp_info[0]);
			}
		}
	}
	public String getInstruction () {
		//return id;
		//return id+"\n"+Integer.toString(idx);
		return Integer.toString(idx);
	}
	public String setInstruction () {
		return type+" "+id;
	}
	public Object clone () throws CloneNotSupportedException {
		Variable copy=(Variable)super.clone();
		if (type!=null)
			copy.setType(new String(type));
		if (id!=null)
			copy.setID(new String(id));
		return copy;
	}
}

