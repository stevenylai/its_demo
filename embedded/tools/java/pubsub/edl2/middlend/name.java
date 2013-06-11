package pubsub.edl2.middlend;
import java.util.*;


public class name extends expression {
	private String fullName;
	public name() {
		createChildren();
	}
	public String getName () {
		return "Nonterminal: name";
	}
	public void generateFullName() {
		if (fullName==null) {
			for (int i=0; i<children.size(); i++) {
				Identifier np = (Identifier)children.get(i);
				if (i==0)
					fullName = np.toString();
				else
					fullName = fullName+"."+np.toString();
			}
		}
	}
	public String getFullName () {
		generateFullName();
		return fullName;
	}
	/*public ClassMethod staticTypeCheckForMethod (SymbolTable t, Vector arglist) throws UndefinedSymbolException, TypeException {
		NameResolver nr = new NameResolver();
		nr.setSymbolTable(t);
		for (int i=0; i<children.size()-1; i++) {
			Identifier child = (Identifier)children.get(i);
			nr.getName(child.toString());
		}
		ClassMethod tmp_method = new ClassMethod(((Identifier)children.get(children.size()-1)).toString());
		tmp_method.setParameters(arglist);
		tmp_method.generateKey();
		//System.out.println("Method to find: "+tmp_method);
		return nr.getMethod(tmp_method);
	}
	public boolean generateCodeForMethod (SymbolTable t, CodeStore codes) throws UndefinedSymbolException, TypeException {
		if (children.size()<2)
			return false;

		composite_statements ws = (composite_statements)getInheritAttribute("composite_statements");
		NameResolver nr = new NameResolver();
		if (ws!=null) {
			nr.setInsideComposite(ws.insideComposite());
			nr.setCompositeID(ws.getID());
		}

		nr.setSymbolTable(t);
		for (int i=0; i<children.size()-1; i++) {
			Identifier child = (Identifier)children.get(i);
			nr.getName(child.toString());
		}

		Vector tmpInstrs = nr.getInstructions();
		for (int i=0; i<tmpInstrs.size(); i++)
			codes.addInstruction((String)tmpInstrs.get(i));
		return true;
	}
	public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		NameResolver nr = new NameResolver();
		nr.setSymbolTable(t);
		//System.out.print("Resolving name: ");
		for (int i=0; i<children.size(); i++) {
			Identifier child = (Identifier)children.get(i);
			nr.getName(child.toString());
			//System.out.print(child.toString()+" ("+nr.getType()+"), with symbol table: "+nr.getSymbolTable().getParentSymbol()+"; ");
		}
		//System.out.println("");
		//System.out.println(((Identifier)children.get(0)).toString()+": Checking if composite ...");
		if (nr.isVariable() && getInheritAttribute("composite_statements")!=null) {
			System.out.println("composite_statements detected, processing...");
			Variable v = nr.getVariable();
			composite_statements ws = (composite_statements)getInheritAttribute("composite_statements");
			if (getNormalAttribute("leftvalue")!=null) { // left value
				ws.addSharedWrite(v);
			} else { // right value
				ws.addSharedRead(v);
			}
		}
		return nr.getType();
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		if (getNormalAttribute("leftvalue")!=null)
			generateLeftValueCode (t, codes);
		else
			generateRightValueCode (t, codes);
	}
	public void generateLeftValueCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		composite_statements ws = (composite_statements)getInheritAttribute("composite_statements");
		NameResolver nr = new NameResolver();
		if (ws!=null) {
			nr.setInsideComposite(ws.insideComposite());
			nr.setCompositeID(ws.getID());
		}
		nr.setSymbolTable(t);
		for (int i=0; i<children.size(); i++) {
			Identifier child = (Identifier)children.get(i);
			if (i<children.size()-1)
				nr.getName(child.toString());
			else
				nr.setName(child.toString());
		}

		if (nr.isVariable()) {
			// Append the instructions
			Vector tmpInstrs = nr.getInstructions();
			for (int i=0; i<tmpInstrs.size(); i++)
				codes.addInstruction((String)tmpInstrs.get(i));
		} else {
			throw new TypeException ("Incorrect use of "+getFullName()+" as left value");
		}
	}
	public void generateRightValueCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		composite_statements ws = (composite_statements)getInheritAttribute("composite_statements");
		NameResolver nr = new NameResolver();
		if (ws!=null) {
			nr.setInsideComposite(ws.insideComposite());
			nr.setCompositeID(ws.getID());
		}
		nr.setSymbolTable(t);
		for (int i=0; i<children.size(); i++) {
			Identifier child = (Identifier)children.get(i);
				nr.getName(child.toString());
		}

		// Append the instructions
		Vector tmpInstrs = nr.getInstructions();
		for (int i=0; i<tmpInstrs.size(); i++)
			codes.addInstruction((String)tmpInstrs.get(i));
	}
	public void adjust () {
		int i=0;
		while (i<children.size()) {
			Object child = children.get(i);
			if (child!=null && child instanceof name) {
				parent.addChild((GenericTreeNode)children.remove(i));
			}
			else
				i++;
		}
		super.adjust();
	}*/
}/*
class NameResolver {
	private SymbolTable sym_table;
	private Vector instructions;
	private CodeStore add_instructions;
	private String firstName;
	private String newName;
	private boolean firstNameResolved;
	private String type;

	private boolean isClassEntry;
	private ClassEntry currentClassEntry;
	private boolean isVariable;
	private Variable currentVariable;

	private boolean insideComposite;
	private int compositeID;

	public NameResolver () {
		instructions = new Vector();
		add_instructions = new CodeStore();
		firstNameResolved = false;
		isClassEntry = isVariable = false;
		insideComposite = false;
	}
	public void setSymbolTable (SymbolTable sym_table) { this.sym_table = sym_table; }
	public SymbolTable getSymbolTable () { return this.sym_table; }
	public boolean isClassEntry () { return isClassEntry; }
	public ClassEntry getClassEntry () { return currentClassEntry; }
	public boolean isVariable () { return isVariable; }
	public Variable getVariable () { return currentVariable; }
	public void setInsideComposite (boolean insideComposite) { this.insideComposite = insideComposite; }
	public boolean insideComposite () { return this.insideComposite; }
	public void setCompositeID (int compositeID) { this.compositeID=compositeID; }

	public Vector getInstructions () {
		this.instructions.addAll(add_instructions.getInstructions());
		return this.instructions;
	}
	public String getType () { return this.type; }

	private void addName (String nm) {
		if (firstName==null)
			firstName = nm;
		else if (firstName!=null && newName==null) {
			newName = nm;
		} else {
			firstName = firstName+"."+newName;
			newName = nm;
		}
	}
	public void getName (String nm) throws UndefinedSymbolException, TypeException {
		addName(nm);
		if (!firstNameResolved) {
			if (!resolveAsVariable(false))
				resolveAsClassEntry(false);
		} else {
			resolveAsField(false);
		}
	}
	public void setName (String nm) throws UndefinedSymbolException, TypeException {
		addName(nm);
		if (!firstNameResolved) {
			if (!resolveAsVariable(true))
				resolveAsClassEntry(true);
		} else {
			resolveAsField(true);
		}
	}
	public ClassMethod getMethod (ClassMethod cm) throws UndefinedSymbolException, TypeException {
		cm.generateKey();
		return (ClassMethod)sym_table.lookUp(cm);
	}
	private void resolveAsClassEntry (boolean toSet) throws UndefinedSymbolException, TypeException {
		if (firstName==null) // nothing to resolve
			return;

		// Try to resolve as ClassEntry
		ClassEntry ce = (ClassEntry)sym_table.lookUp(new ClassEntry(firstName));
		if (ce!=null) {
			isClassEntry = true;
			isVariable = false;
			currentClassEntry = ce;
			type = ce.getID();

			if (newName==null) // Simple name (so far), stop
				return;
			ClassField cf = (ClassField)(ce.getTable().lookUp(new Variable(newName)));
			if (cf!=null && cf.isStatic()) {
				firstNameResolved = true; // don't set as resolved until the first field (have to be static) is resolved
				isClassEntry = false;
				isVariable = true;
				currentVariable = cf;
				sym_table = cf.getTable();
				instructions.clear();
				if (toSet) {
					if (insideComposite)
						cf.setCompositeInstruction(compositeID, instructions);
					else {
						instructions.add(cf.setInstruction());
						if (currentVariable.isSharedRead()||currentVariable.isSharedWrite())
							currentVariable.generateCompositeInstructions(add_instructions, 0);
					}
				} else {
					if (insideComposite)
						cf.getCompositeInstruction(compositeID, instructions);
					else
						instructions.add(cf.getInstruction());
				}
				type = cf.getType();
			} else if (cf!=null) {
				isClassEntry = false;
				isVariable = true;
				throw new TypeException (cf);
			} else {
				throw new UndefinedSymbolException (new Variable(newName));
			}
		}
	}
	private boolean resolveAsVariable (boolean toSet) throws UndefinedSymbolException, TypeException {
		if (firstName == null) // Nothing to resolve
			return false;

		// Try to resolve as variable
		Variable v = (Variable)sym_table.lookUp(new Variable(firstName));
		if (v!=null) {
			firstNameResolved = true;
			isClassEntry = false;
			isVariable = true;
			currentVariable = v;
			if (v.isPrimitiveType() && newName==null) { // Simple name
				if (toSet) {
					if (insideComposite)
						currentVariable.setCompositeInstruction(compositeID, instructions);
					else {
						instructions.add(v.setInstruction());
						if (currentVariable.isSharedRead() ||currentVariable.isSharedWrite()) {
							currentVariable.generateCompositeInstructions(add_instructions, 0);
						}
					}
				} else {
					if (insideComposite)
						currentVariable.getCompositeInstruction(compositeID, instructions);
					else
						instructions.add(v.getInstruction());
				}
				type = v.getType();
			} else if (!v.isPrimitiveType()) {
				ClassEntry ce = (ClassEntry)sym_table.lookUp(new ClassEntry(v.getType()));
				if (ce!=null)
					sym_table = ce.getTable();
				else
					throw new UndefinedSymbolException(new ClassEntry(v.getType()));

				if (toSet) {
					if (insideComposite)
						currentVariable.setCompositeInstruction(compositeID, instructions);
					else {
						instructions.add(v.setInstruction());
						if (currentVariable.isSharedRead() ||currentVariable.isSharedWrite()) {
							currentVariable.generateCompositeInstructions(add_instructions, 0);
						}
					}
				} else {
					if (insideComposite)
						currentVariable.getCompositeInstruction(compositeID, instructions);
					else
						instructions.add(v.getInstruction());
				}
				type = v.getType();
			} else {
				throw new TypeException(v);
			}
			return true;
		} else
			return false;
	}
	private void resolveAsField (boolean toSet) throws UndefinedSymbolException, TypeException {
		if (newName == null) {
			return;
		}

		Variable v = (Variable)sym_table.lookUp(new Variable(newName));
		if (v!=null && v instanceof ClassField) {
			isClassEntry = false;
			isVariable = true;
			ClassField cf = (ClassField)v;
			if (!cf.isPrimitiveType()) {
				ClassEntry ce = (ClassEntry)sym_table.lookUp(new ClassEntry(cf.getType()));
				if (ce!=null)
					sym_table = ce.getTable();
				else
					throw new UndefinedSymbolException(new ClassEntry(cf.getType()));
			}

			if (cf.isStatic()) {
				currentVariable = v;
				instructions.clear();
			}
			if (toSet) {
				//if (insideComposite)
					//cf.setCompositeInstruction(compositeID, instructions, cf.getLength(), cf.getIndex());
				//else {
					instructions.add("settargetheap "+cf.getIndex());
					if (currentVariable!=null && (currentVariable.isSharedRead() ||currentVariable.isSharedWrite())) {
						if (cf.isStatic())
							currentVariable.generateCompositeInstructions(add_instructions, 0);
						else
							currentVariable.generateCompositeInstructions(add_instructions, cf.getIndex());
					}
				//}
			} else {
				//if (insideComposite)
					//cf.getCompositeInstruction(compositeID, instructions, cf.getIndex());
				//else
					instructions.add("2gettargetheap8 "+cf.getIndex());
			}
			type = cf.getType();
		} else {
			throw new UndefinedSymbolException (new Variable(newName));
		}
	}
}*/
