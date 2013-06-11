package pubsub.edl2.middlend;


import java.util.*;

public class variable_declarators extends GenericTreeNode {
	public variable_declarators() {
		createChildren();
	}
	public Vector getVariableList(Vector modifierList, String typeStr) {
		Vector varList = new Vector();

		return varList;
	}
	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException {
		Variable v_template = (Variable)getNormalAttribute ("variable_template");
		for (int i=0; i<children.size(); i++) {
			variable_declarator vd = (variable_declarator)children.get(i);
			if (vd!=null) {
				try {
					Variable new_var = (Variable)v_template.clone();
					new_var.setID(vd.getID());
					new_var.generateKey();
					t.addSymbol(new_var);
				} catch (CloneNotSupportedException e) {
					e.printStackTrace();
				}
			}
		}
	}*/
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		Variable v_template = (Variable)getNormalAttribute ("variable_template");
		String targetType = v_template.getType();
		for (int i=0; i<children.size(); i++) {
			variable_declarator vd = (variable_declarator)children.get(i);
			if (vd!=null) {
				vd.staticTypeCheck(t, targetType);
			} // end of if
		} // end of for
		return targetType;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		for (int i=0; i<children.size(); i++) {
			variable_declarator vd = (variable_declarator)children.get(i);
			if (vd!=null) {
				vd.generateCode(t, codes);
			} // end of if
		} // end of for
	}*/
	public String getName () {
		return "Nonterminal: variable_declarators";
	}
}
