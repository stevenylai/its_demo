package pubsub.edl2.symbols;

import java.io.*;
import java.util.*;
import pubsub.edl2.middlend.*;

public class SymbolTable {
	private Hashtable table;
	private SymbolTable parentTable;
	private AbstractSymbol parentSymbol;

	private Vector blocks;
	private int blockIdx;

	private boolean finishedTypeCheck;

	private boolean isStatic;

	private Vector class_list; // for top-level symbol table only

	public SymbolTable () {
		table = new Hashtable();
		blocks = new Vector();
		class_list = new Vector();
		parentTable = null;
		finishedTypeCheck = false;
		isStatic=false;
		blockIdx=0;
	}

	public void setParentTable (SymbolTable parentTable) { this.parentTable=parentTable; }
	public void setParentSymbol (AbstractSymbol parentSymbol) { this.parentSymbol=parentSymbol; }
	public void setStatic (boolean isStatic) { this.isStatic=isStatic; }

	public SymbolTable getParentTable () { return this.parentTable; }
	public AbstractSymbol getParentSymbol () { return this.parentSymbol; }
	public boolean isStatic () { return this.isStatic; }

	public SymbolTable addBlock () {
		SymbolTable sym_table = new SymbolTable();
		sym_table.setStatic(isStatic());
		sym_table.setParentTable(this);
		blocks.add(sym_table);
		return sym_table;
	}
	public SymbolTable getBlock(int idx) { return (SymbolTable)blocks.get(idx); }
	public Vector getBlocks() { return this.blocks; }
	public SymbolTable getNextBlock() {
		if (blockIdx>=blocks.size())
			blockIdx=0;
		//System.out.println("Getting block no. "+blockIdx+", total blocks: "+blocks.size()+", parent symbol: "+parentSymbol.getKey());
		return (SymbolTable)blocks.get(blockIdx++);
	}
	public void resetBlockIndex() { this.blockIdx=0; }

	public void addSymbol (AbstractSymbol sym) throws SymbolRedeclarationException{
		if (lookUp(sym)!=null) {
			throw new SymbolRedeclarationException(sym);
		}
		table.put(sym.getKey(), sym);
		sym.setParentTable(this);
		if (sym instanceof ClassField && parentSymbol instanceof ClassEntry) {
			ClassEntry ce = (ClassEntry)parentSymbol;
			ClassField cf = (ClassField)sym;
			ce.addField(cf);
			System.out.println("Symbol: "+sym+" has been added with index: "+cf.getIndex()+" with type: "+cf.getType());
		}	else if (sym instanceof ClassMethod && parentSymbol instanceof ClassEntry) {
			ClassEntry ce = (ClassEntry)parentSymbol;
			ClassMethod cm = (ClassMethod)sym;
			ce.addMethod(cm);
			System.out.println("Method: "+cm+" has been added to "+ce);
		} else if (sym instanceof ClassEntry) {
			class_list.add(sym);
			System.out.println("Symbol: "+sym+" has been added to "+parentSymbol);
		}/* else if (sym instanceof Variable) {
			ClassMethod cm = getParentMethod();
			Variable v = (Variable)sym;
			cm.addVariable(v);
			System.out.println("Symbol: "+sym+" has been added with index: "+v.getIndex()+" with type: "+v.getType());
		}*/ else
			System.out.println("Symbol: "+sym+" has been added to "+parentSymbol);
	}
	public SymbolTable getCurrentClassTable () {
		if (parentSymbol instanceof ClassEntry)
			return this;
		else if (parentTable != null)
			return parentTable.getCurrentClassTable();
		else
			return null;
	}
	public ClassEntry getCurrentClass() {
		if (parentSymbol instanceof ClassEntry)
			return (ClassEntry)parentSymbol;
		else if (parentTable != null)
			return parentTable.getCurrentClass();
		else
			return null;
	}
	public ClassMethod getParentMethod () {
		if (parentSymbol instanceof ClassMethod) {
			return (ClassMethod)parentSymbol;
		} else if (parentTable!=null) {
			return parentTable.getParentMethod();
		} else
			return null;
	}
	public SymbolTable getParentClassTable () {
		if (parentSymbol instanceof ClassEntry) {
			ClassEntry ce = (ClassEntry)parentSymbol;
			ClassEntry ce_parent = ce.getParentClass();
			if (ce_parent!=null)
				return ce_parent.getTable();
			else
				return null;
		}
		else if (parentTable != null)
			return parentTable.getParentClassTable();

		return null;
	}
	public void typeCheck () throws TypeException, UndefinedSymbolException {
		while (!finishedTypeCheck) {
			finishedTypeCheck = true;
			for (int i=0; i<class_list.size(); i++) {
				ClassEntry ce = (ClassEntry)class_list.get(i);
				if (!ce.typeCheck())
					finishedTypeCheck=false;
				//else
				//System.out.println("Finished type checking for: "+ce.getID());
			}
		}
	}
	public AbstractSymbol lookUpCurrent (AbstractSymbol sym) {
		sym.generateKey();
		AbstractSymbol s = (AbstractSymbol)table.get(sym.getKey());
		return s;
	}
	public AbstractSymbol lookUp (AbstractSymbol sym) {
		sym.generateKey();
		AbstractSymbol s = (AbstractSymbol)table.get(sym.getKey());
		if (s==null && parentTable!=null)
			return parentTable.lookUp(sym);
		return s;
	}
}
