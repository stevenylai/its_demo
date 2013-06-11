package pubsub.edl2.middlend;


import java.util.*;

public class field_access extends expression {
	private String parentType;
	public field_access() {
		createChildren();
	}
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		Object child = children.get(0);
		if (child instanceof SUPER) {
			Identifier id = (Identifier)children.get(1);
			// Get the correct symbol table
			ClassField cf = (ClassField)(t.getParentClassTable().lookUp(new Variable(id.toString())));
			if (cf!=null) {
				return cf.getType();
			} else {
				throw new UndefinedSymbolException(new Variable(id.toString()));
			}
		} else if (child instanceof THIS) {
			Identifier id = (Identifier)children.get(1);
			// Get the correct symbol table
			ClassField cf = (ClassField)(t.getCurrentClassTable().lookUp(new Variable(id.toString())));
			if (cf!=null) {
				return cf.getType();
			} else {
				throw new UndefinedSymbolException(new Variable(id.toString()));
			}
		} else if (child instanceof Literal) {
			throw new TypeException("Incorrect use of literal in field access");
		} else if (child instanceof expression) {
			String childType = ((expression)child).staticTypeCheck(t);
			Identifier id = (Identifier)children.get(1);
			if (childType!=null && !TypeInfo.isPrimitiveType(childType)) {
				ClassEntry class_type = (ClassEntry)t.lookUp(new ClassEntry(childType));
				if (class_type!=null) {
					parentType = class_type.getID();
					ClassField class_field = (ClassField)(class_type.getTable().lookUp(new ClassField(id.toString())));
					if (class_field!=null) {
						return class_field.getType();
					}
					else {
						throw new TypeException(id+"is not a member of "+class_type.getID());
					}
				}
				else {
					throw new UndefinedSymbolException ("Undefined symbol: "+class_type.getID());
				}
			} else {
				throw new TypeException ("Incorrect symbol access for primitive type");
			}
		}
		return null;
	}
	public void generateCode (SymbolTable t, CodeStore codes, boolean toSet) throws UndefinedSymbolException,TypeException {
		Object child = children.get(0);
		if (child instanceof SUPER) {
			Identifier id = (Identifier)children.get(1);
			// Get the correct symbol table
			ClassField cf = (ClassField)(t.getParentClassTable().lookUp(new Variable(id.toString())));
			if (cf!=null) {
				//if (!cf.isStatic())
					//instructions.add("getlocal "+SUPER.super_address);
				if (toSet) {
					codes.addInstruction(cf.setInstruction());
					// FIXME: should consider cf's type
					if (cf.isSharedRead() ||cf.isSharedWrite()) {
							cf.generateCompositeInstructions(codes, 0);
						}
				} else
					codes.addInstruction(cf.getInstruction());
			} else {
				throw new UndefinedSymbolException(new Variable(id.toString()));
			}
		} else if (child instanceof Literal) {
			throw new UndefinedSymbolException("Incorrect use of literal in field access");
		} else if (child instanceof THIS) {
			Identifier id = (Identifier)children.get(1);
			// Get the correct symbol table
			ClassField cf = (ClassField)(t.getCurrentClassTable().lookUp(new Variable(id.toString())));
			if (cf!=null) {
				//if (!cf.isStatic())
					//instructions.add("getlocal "+THIS.this_address);
				if (toSet) {
					codes.addInstruction(cf.setInstruction());
					// FIXME: should consider cf's type
					if (cf.isSharedRead() ||cf.isSharedWrite()) {
							cf.generateCompositeInstructions(codes, 0);
					}
			} else
					codes.addInstruction(cf.getInstruction());
			} else {
				throw new UndefinedSymbolException(new Variable(id.toString()));
			}
		} else if (child instanceof expression) {
			// Use 'parentType'
			ClassEntry ce = (ClassEntry)t.lookUp(new ClassEntry(parentType));
			Identifier id = (Identifier)children.get(1);
			if (ce!=null) {
				ClassField cf = (ClassField)(ce.getTable().lookUp(new ClassField(id.toString())));
				if (cf!=null) {
					if (cf.isStatic()) {
						if (toSet)
							codes.addInstruction(cf.setInstruction());
						else
							codes.addInstruction(cf.getInstruction());
					} else {
						expression e = (expression)child;
						e.generateCode(t, codes);
						if (toSet)
							codes.addInstruction("2settargetheap8 "+cf.getIndex());
						else
							codes.addInstruction("2gettargetheap8 "+cf.getIndex());
					}
				} else {
					throw new TypeException(id+"is not a member of "+ce.getID());
				}
			} else {
				throw new UndefinedSymbolException ("Undefined symbol: "+ce.getID());
			}
		}
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		if (!(getNormalAttribute("leftvalue")==null))
			generateCode (t, codes, true);
		else
			generateCode (t, codes, false);
	}*/
	public String getName () {
		return "Nonterminal: field_access";
	}
}
