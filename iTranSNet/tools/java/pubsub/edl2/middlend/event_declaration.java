package pubsub.edl2.middlend;


import java.util.*;

public class event_declaration extends GenericTreeNode {
	public String id;

	public event_declaration() {
		createChildren();
	}
	public event_declaration(String id) {
		this();
		// should be first converted to a full quantified name
		this.id=id;
	}

	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException {
		if (class_entry==null) {
			createClassEntry();
		}

		// Add to the symbol table
		try {
			t.addSymbol(class_entry);
		} catch (SymbolRedeclarationException e) {}
		field_declarations cbd = (field_declarations)children.get(0); // class body
		if (cbd!=null) {
			cbd.constructTable(class_entry.getTable());
		}

		expression e1 = (expression)children.get(1); // where clause
		if (e1!=null) {
			e1.constructTable(class_entry.getTable());
		}

		expression e2 = (expression)children.get(2); // area clause
		if (e2!=null) {
			e2.constructTable(class_entry.getTable());
		}
	}*/
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		if (class_entry==null) {
			createClassEntry();
		}
		AbstractSymbol sym = t.lookUp(class_entry);
		if (sym==null) {
			throw new UndefinedSymbolException("Class not appearing in the symbol table (impossible to reach here)");
		}
		field_declarations cbd = (field_declarations)children.get(0); // class body
		if (cbd!=null) {
			cbd.staticTypeCheck (class_entry.getTable());
		}

		expression e1 = (expression)children.get(1); // where clause
		if (e1!=null) {
			e1.staticTypeCheck (class_entry.getTable());
		}

		expression e2 = (expression)children.get(2); // area clause
		if (e2!=null) {
			e2.staticTypeCheck(class_entry.getTable());
		}
		return class_entry.getID();
	}
	public void generateCode (SymbolTable t, CodeRepository codes) throws UndefinedSymbolException,TypeException {
		if (class_entry==null) {
			createClassEntry();
		}
		AbstractSymbol sym = t.lookUp(class_entry);
		if (sym==null) {
			System.out.println("Class not appearing in the symbol table (impossible to reach here)");
			return;
		}
		ClassCode cd = new ClassCode(class_entry);
		codes.addClass(cd);
		field_declarations cbd = (field_declarations)children.get(0); // event body
		if (cbd!=null) {
			cbd.generateCode (sym.getTable(), cd);
		}

		expression e1 = (expression)children.get(1); // where clause
		if (e1!=null) {
			MethodCode c = new MethodCode("where");
			cd.addMethod(c);
			e1.generateCode (sym.getTable(), c);
		}

		expression e2 = (expression)children.get(2); // where clause
		if (e2!=null) {
			MethodCode c = new MethodCode("area");
			cd.addMethod(c);
			e2.generateCode (sym.getTable(), c);
		}
	}*/
	public String getName () {
		return "Nonterminal: event_declaration: "+id;
	}
}
