package pubsub.edl2.symbols;

public class AbstractSymbol implements Cloneable{
	private String key;
	private SymbolTable parentTable;
	private SymbolTable subTable;

	protected static int globalIndex;

	static {
		globalIndex=0;
	}

	public AbstractSymbol () {
		subTable = new SymbolTable();
		subTable.setParentSymbol(this);
	}
	public void setKey (String key) { this.key=key; }
	public void setSymbolTable (SymbolTable subTable) { this.subTable=subTable; }
	public void setParentTable (SymbolTable parentTable) {
		this.parentTable=parentTable;
		subTable.setParentTable(parentTable);
	}

	public String getKey () { return this.key; }
	public SymbolTable getTable () { return this.subTable; }
	public SymbolTable getParentTable () { return this.parentTable; }
	public void generateKey () { }
	public Object clone () throws CloneNotSupportedException{
		AbstractSymbol copy=(AbstractSymbol)super.clone();
		copy.setSymbolTable(new SymbolTable());
		copy.setParentTable(parentTable);
		if (key!=null)
			copy.setKey(new String(key));
		return copy;
	}
	public String toString () { return getKey(); }
}

