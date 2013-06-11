package pubsub.edl2.backendPSware;

import pubsub.edl2.middlend.*;
import pubsub.edl2.symbols.*;
import pubsub.edl2.receiver.*;

public class CodeGenerator {
	int expressionCounter=0;

	public CodeGenerator () {
		expressionCounter=0;
	}
	public int generateMask(int i) {
		int mask=0x80;
		mask=mask>>i;
		return mask;
	}
	public byte generateType(ClassEntry ce) {
		byte result = (byte)0;
		if (ce.subscribed) {
			result=(byte)((int)result|generateMask(0));
		}
		if (!ce.isPrimitiveEvent) {
			result=(byte)((int)result|generateMask(1));
		}
		return result;
	}
	public void generateCode(GenericTreeNode node, SymbolTable table, CodeStore codes) {
		if (node instanceof event_declaration) {
			ClassEntry class_entry = (ClassEntry)node.getInheritAttribute("class_entry");
			ClassCode cd = new ClassCode(class_entry);
			((CodeRepository)codes).addClass(cd);
			// change codes
			codes=cd;
			table=class_entry.getTable();
			// ID==0 is system event
			if (class_entry.getSubscribeID()>0) {
				codes.addInstruction("event_"+class_entry.getID()+": 2create8 "+class_entry.getSubscribeID());
				codes.addInstruction("2except10 "+((event_declaration)node).id+"_where");
			}

			// Generate meta message here!
			CodeRepository topcodes = codes.getTopLevelCode();

			EventMetaInfo meta = new EventMetaInfo();
			meta.ID=class_entry.getID();
			for (int i=0; i<class_entry.fields.size(); i++) {
				ClassField cf = class_entry.fields.get(i);
				meta.fields.add(cf.getID());
			}
			meta.subID = (short)class_entry.getSubscribeID();
			meta.length = (short)class_entry.fields.size();
			meta.type = (short)generateType(class_entry);
			meta.rate = 1;
			meta.lifetime = 1;
			topcodes.meta.add(meta);
		}

		for (int i=0; i<node.getChildren().size(); i++) {
			Object child = node.getChildren().get(i);
			if (child instanceof GenericTreeNode) {
				if (node instanceof event_declaration && i==2) {
					MethodCode mc = new MethodCode("WHERE");
					String eventID=((event_declaration)node).id;
					mc.label=eventID+"_where";
					((ClassCode)codes).addMethod(mc);
					codes=mc;
				}
				generateCode((GenericTreeNode)child, table, codes);
			}
		} // end of for

		if (node instanceof variable_declarator) {
			variable_declarator vd = (variable_declarator)node;
			if (vd.getChildren().size()>1) {
				Variable v = (Variable)table.lookUp(new Variable(vd.getID()));
				if (v!=null && v.isPrimitiveType()) {
					ClassEntry class_entry = (ClassEntry)node.getInheritAttribute("class_entry");
					codes.addInstruction("2ref8 "+Integer.toString(class_entry.getSubscribeID()));
					codes.addInstruction("2offset8 "+Integer.toString(v.getIndex()));
					codes.addInstruction("set");
				}
			} // end of if
		} else if (node instanceof name) {
			SymbolTable name_table=table;
			for (int i=0; i<node.getChildren().size(); i++) {
				Identifier var_id = (Identifier)node.getChildren().get(i);
				if (var_id!=null) {
					Variable v = (Variable)name_table.lookUp(new Variable(var_id.toString()));
					ClassEntry ce = (ClassEntry)name_table.lookUp(new ClassEntry(var_id.toString()));
					if (v!=null) {
						name_table=v.getTable();
						if (i==0) {
							if (v.isPrimitiveType()) {
								ClassEntry class_entry = (ClassEntry)node.getInheritAttribute("class_entry");
								codes.addInstruction("2ref8 "+Integer.toString(class_entry.getSubscribeID()));
								codes.addInstruction("2offset8 "+Integer.toString(v.getIndex()));
								codes.addInstruction("get");
							} else {
								ClassEntry class_entry = (ClassEntry)name_table.lookUp(new ClassEntry(v.getType()));
								codes.addInstruction("2ref8 "+Integer.toString(class_entry.getSubscribeID()));
							}
						} else {
							codes.addInstruction("2offset8 "+Integer.toString(v.getIndex()));
							codes.addInstruction("get");
						}
					} else if (i==0 && ce!=null) {
						name_table=ce.getTable();
						codes.addInstruction("2ref8 "+Integer.toString(ce.getSubscribeID()));
					} else {
						System.out.println("Unknown variable: "+var_id.toString());
					}
				}
			}
		} else if (node instanceof expression) {
			generateCodeForExpression(node, table, codes);
		} else if (codes instanceof MethodCode) {
			MethodCode mc = (MethodCode)codes;
			ClassEntry class_entry = (ClassEntry)node.getInheritAttribute("class_entry");
			String class_label="";

			if (class_entry==null)
				System.out.println("Cannot find class type for eval instruction!");
			else
				class_label=" event_"+class_entry.getID();
			codes.addInstruction(mc.label+": 2eval10"+class_label);
		}
	}

	public void generateCodeForExpression(GenericTreeNode node, SymbolTable table, CodeStore codes) {
		String expLabel = (String)node.getNormalAttribute("exprLabel");
		if (expLabel!=null) {
			codes.addLabel(expLabel);
		}

		if (node instanceof additive_expression) {
			if (((additive_expression)node).oper.equals("+"))
				codes.addInstruction("add");
			else if (((additive_expression)node).oper.equals("-"))
				codes.addInstruction("sub");
		} else if (node instanceof multiplicative_expression) {
			if (((multiplicative_expression)node).oper.equals("*"))
				codes.addInstruction("mul");
			if (((multiplicative_expression)node).oper.equals("/"))
				codes.addInstruction("div");
		} else if (node instanceof conditional_and_expression) {
			codes.addInstruction("and");
		} else if (node instanceof conditional_or_expression) {
			codes.addInstruction("or");
		} else if (node instanceof equality_expression) {
			String op = ((equality_expression)node).oper;
			if (op.equals("!="))
				codes.addInstruction("neq");
			else if (op.equals("=="))
				codes.addInstruction("eq");
		} else if (node instanceof relational_expression) {
			String op = ((relational_expression)node).oper;
			if (op.equals(">"))
				codes.addInstruction("gt");
			else if (op.equals("<"))
				codes.addInstruction("lt");
			else if (op.equals(">="))
				codes.addInstruction("ge");
			else if (op.equals("<="))
				codes.addInstruction("le");
		} else if (node instanceof Literal) {
			//codes.appendInstruction("l"+((Literal)node).literal);
			codes.addInstruction("2pushc10 "+((Literal)node).literal);
		}
	}

	public void generateRightValueCode (name node, SymbolTable table, CodeStore codes) {
		generateLeftValueCode(node, table, codes);
	}
	public void generateLeftValueCode (name node, SymbolTable table, CodeStore codes) {
		for (int i=0; i<node.getChildren().size(); i++) {
			Identifier child = (Identifier)(node.getChildren().get(i));
			Variable v = (Variable)table.lookUp(new Variable(child.toString()));
			if (v!=null) {
				codes.appendInstruction("p"+v.getIndex());
			} else
				System.out.println("Symbol not found!");
		}
	} // end of generateLeftValueCode
}
