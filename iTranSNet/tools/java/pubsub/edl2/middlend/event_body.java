package pubsub.edl2.middlend;

import java.util.*;

public class event_body extends statement {
	public event_body() {
		createChildren();
	}
	public String getName () {
		return "Nonterminal: event_body";
	}
	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException	{
		Object child = children.get(0);
		if (child instanceof local_variable_declaration) {
			local_variable_declaration lvd = (local_variable_declaration)child;
			lvd.constructTable(t);
		} else if (child instanceof statement) {
			statement s = (statement)child;
			s.constructTable(t);
		}
	}*/
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		Object child = children.get(0);
		if (child instanceof local_variable_declaration) {
			local_variable_declaration lvd = (local_variable_declaration)child;
			return lvd.staticTypeCheck(t);
		} else if (child instanceof statement) {
			statement s = (statement)child;
			return s.staticTypeCheck(t);
		}
		return null;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		Object child = children.get(0);
		if (child instanceof local_variable_declaration) {
			local_variable_declaration lvd = (local_variable_declaration)child;
			lvd.generateCode(t, codes);
		} else if (child instanceof statement) {
			statement s = (statement)child;
			s.generateCode(t, codes);
		}
	}*/
}
