package pubsub.edl2.frontendComposite;

import pubsub.edl2.middlend.*;
import pubsub.edl2.symbols.*;
import java.util.*;

public class TypeChecker {

	public ClassEntry createClassEntry (String id) {
			ClassEntry class_entry = new ClassEntry(id);

			System.out.print("Event: "+class_entry.getID());
			System.out.println("");
			class_entry.generateKey();
			return class_entry;
	}
	// Add class/event entries
	// For each entry, add attributes
	public void constructTable(GenericTreeNode node, SymbolTable table) throws TypeException, SymbolRedeclarationException{
		if (node instanceof event_declaration) {
			event_declaration ce = (event_declaration)node;
			ClassEntry class_entry = (ClassEntry)node.getInheritAttribute("class_entry");
			if (class_entry==null)
				class_entry=createClassEntry(ce.id);
			node.addInheritAttribute("class_entry", class_entry);
			try {
				table.addSymbol(class_entry);
			} catch (SymbolRedeclarationException e) {}
			table=class_entry.getTable();
		} else if (node instanceof field_declaration) {
			field_declaration fd = (field_declaration)node;
			ClassField cf = new ClassField ();
			// FIXME: add to attribute instead of creating a 'getType' method?
			cf.setType(fd.getType());
	
			variable_declarators vd = (variable_declarators)node.getChildren().get(1); // list of variables
			vd.addNormalAttribute ("variable_template", cf);
			((GenericTreeNode)node.getChildren().get(0)).addNormalAttribute("type", node);
		} else if (node instanceof variable_declarators) {
			//variable_declarators vd = (variable_declarators)node;
			Variable v_template = (Variable)node.getNormalAttribute ("variable_template");
			for (int i=0; i<node.getChildren().size(); i++) {
				variable_declarator vd = (variable_declarator)node.getChildren().get(i);
				if (vd!=null) {
					try {
						Variable new_var = (Variable)v_template.clone();
						new_var.setID(vd.getID());
						new_var.generateKey();
						table.addSymbol(new_var);
						vd.addNormalAttribute("variable_declarator", new_var);
					} catch (CloneNotSupportedException e) {
						e.printStackTrace();
					}
				}
			} // end of for
		}

		for (int i=0; i<node.getChildren().size(); i++) {
			Object child = node.getChildren().get(i);
			if (child instanceof GenericTreeNode) {
				constructTable((GenericTreeNode)child, table);
			}
		}
	} // end of constructTable
	public String staticTypeCheck (GenericTreeNode node, SymbolTable table) throws UndefinedSymbolException, TypeException {
		String current_type=null;
		boolean toCheck=false;
		if (node instanceof event_declaration) {
			ClassEntry class_entry = (ClassEntry)node.getInheritAttribute("class_entry");
			if (node.getChildren().get(1)==null) {
				//System.out.println("Primitive event: "+class_entry.getID());
				class_entry.isPrimitiveEvent=true;
			} else {
				class_entry.isPrimitiveEvent=false;
			}
			table=class_entry.getTable();
		} else if (node instanceof variable_declarators) {
			for (int i=0; i<node.getChildren().size(); i++) {
				variable_declarator vd = (variable_declarator)node.getChildren().get(i);
				if (vd!=null) {
					Variable new_var=(Variable)vd.getNormalAttribute("variable_declarator");
					if (!new_var.isPrimitiveType()) {
						ClassEntry ce = (ClassEntry)table.lookUp(new ClassEntry(new_var.getType()));
						if (ce!=null)
							new_var.setParentTable(ce.getTable());
						else
							System.out.println("Unknown class type: "+new_var.getType());
					}
					current_type=new_var.getType();
				}
			}
		} else if (node instanceof variable_declarator) {
			Variable new_var=(Variable)node.getNormalAttribute("variable_declarator");
			current_type=new_var.getType();
			Identifier var_id = (Identifier)node.getChildren().get(0);
			if (var_id!=null) {
				var_id.addNormalAttribute("variable_declarator", new_var);
			}
			toCheck=true;
		} else if (node instanceof Identifier) {
			Variable new_var=(Variable)node.getNormalAttribute("variable_declarator");
			if (new_var!=null) {
				current_type=new_var.getType();
			}
		// Possible places for 'name':
		// expression: class field, etc
		} else if (node instanceof name) {
			SymbolTable name_table=table;
			for (int i=0; i<node.getChildren().size(); i++) {
				Identifier var_id = (Identifier)node.getChildren().get(i);
				if (var_id!=null) {
					Variable v = (Variable)name_table.lookUp(new Variable(var_id.toString()));
					ClassEntry ce = (ClassEntry)name_table.lookUp(new ClassEntry(var_id.toString()));
					if (v!=null) {
						current_type=v.getType();
						name_table=v.getTable();
					} else if (i==0 && ce!=null){
						current_type=var_id.toString();
						name_table=ce.getTable();
					} else {
						System.out.println("Unknown variable: "+var_id.toString());
					}
				}
			}
		} else if (node instanceof Literal) {
			Literal l = (Literal)node;
			current_type=l.getType();
		} else if (node instanceof expression) {
			toCheck=true;
		} else if (node instanceof subscribe_statement) {
			Identifier var_id = (Identifier)node.getChildren().get(0);
			ClassEntry ce = (ClassEntry)table.lookUp(new ClassEntry(var_id.toString()));
			if (ce==null) {
				System.out.println("Subscribed event not defined: "+var_id.toString());
			} else {
				ce.subscribed=true;
			}
		}

		//System.out.println("Static type checking for: "+node.getName()+", toCheck: "+toCheck);
		String previousChildType=null;
		GenericTreeNode previousChild=null;
		for (int i=0; i<node.getChildren().size(); i++) {
			Object child = node.getChildren().get(i);
			if (child instanceof GenericTreeNode) {
				GenericTreeNode childNode=(GenericTreeNode)child;
				//System.out.println("Doing static type checking for: "+childNode.getName());
				String childType=staticTypeCheck(childNode, table);
				if (i==0) {
					previousChildType=childType;
					previousChild=childNode;
				} else if (toCheck && !TypeInfo.typeMatch(previousChildType, childType))
					System.out.println("Type not matching: "+previousChild.getName()+"("+previousChildType+") "+childNode.getName()+"("+childType+")");
				else if (toCheck)
					System.out.println("Type matching: "+previousChild.getName()+"("+previousChildType+") "+childNode.getName()+"("+childType+")");
			}
		}

		if (node instanceof equality_expression || node instanceof relational_expression) {
			current_type="boolean";
		} else if (node instanceof expression && previousChildType!=null) {
			current_type=previousChildType;
		}

		return current_type;
	}
}
