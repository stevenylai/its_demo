package pubsub.edl2.middlend;


import java.util.*;

public class method_invocation extends expression {
	public method_invocation() {
		createChildren();
	}
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		// get the argument list
		argument_list al = (argument_list)children.get(children.size()-1);
		Vector args = new Vector();
		if (al!=null)
			args = al.staticTypeCheck(t);

		Object child = children.get(0);
		if (child instanceof name) { // name(argulist)
			name nm = (name)child;
			currentMethod = nm.staticTypeCheckForMethod(t, args);
			currentMethod.generateKey();
			if (currentMethod!=null)
				return currentMethod.getType();
			else {
				throw new UndefinedSymbolException("Method: "+nm.getFullName()+" is not defined");
			}
		} else if (child instanceof Literal) {
			System.out.println("Incorrect use of literal in method invocation");
		} else if (child instanceof THIS) { // THIS.Identifier.(argulist)
			Identifier id = (Identifier)children.get(1);
			ClassMethod cm = new ClassMethod(id.toString());
			cm.setParameters(args);
			// Get the correct symbol table
			currentMethod = (ClassMethod)(t.lookUp(cm));
			if (currentMethod!=null) {
				return currentMethod.getType();
			} else {
				throw new UndefinedSymbolException(cm);
			}
		} else if (child instanceof SUPER) { // SUPER.Identifier.(argulist)
			Identifier id = (Identifier)children.get(1);
			ClassMethod cm = new ClassMethod(id.toString());
			cm.setParameters(args);
			// Get the correct symbol table
			currentMethod = (ClassMethod)(t.getParentClassTable().lookUp(cm));
			if (currentMethod!=null) {
				return currentMethod.getType();
			} else {
				throw new UndefinedSymbolException(cm);
			}
		} else { // expression.Identifier.(argulist)
			expression e = (expression)child;
			String parentType = e.staticTypeCheck (t);
			if (parentType!=null && !TypeInfo.isPrimitiveType(parentType)) {
				ClassEntry ce = (ClassEntry)t.lookUp(new ClassEntry(parentType));
				if (ce!=null) {
					ClassMethod tmp_method = new ClassMethod(((Identifier)children.get(1)).toString());
					tmp_method.setParameters(args);
					currentMethod = (ClassMethod)ce.getTable().lookUp(tmp_method);
					if (currentMethod!=null)
						return currentMethod.getType();
					else {
						throw new UndefinedSymbolException("Method: "+tmp_method.getID()+" is not defined in: "+ce.getID());
					}
				} else {
					throw new UndefinedSymbolException ("Cannot resolve class: "+parentType);
				}
			} else {
				throw new TypeException ("Type: "+parentType+" doesn't have method");
			}
		}
		return null;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		// get the argument list
		argument_list al = (argument_list)children.get(children.size()-1);
		if (al!=null) {
			codes.addInstruction("2createparameter8 "+currentMethod.getParameterSize());
			al.generateCode(t, codes);
		} else {
			codes.addInstruction("2createparameter8 0");
		}

		Object child = children.get(0);
		if (child instanceof name) { // name.(argulist)
			//if (!currentMethod.getType().equals("void"))
				codes.addInstruction("createreturn");
			name nm = (name)child;
			codes.addInstruction("2createlocal8 "+currentMethod.getLocalSize());
			if (!nm.generateCodeForMethod(t, codes)) {
				// FIXME: need some mechanisms when code is generated inside the walkthrough block.
				codes.addInstruction("2getlocal8 "+THIS.this_address);
			}
			codes.addInstruction("2setcalleelocal8 "+THIS.this_address);
			codes.addInstruction("pop");
			codes.addInstruction("2call8 "+currentMethod.getLabel());
		} else if (child instanceof Literal) {
			System.out.println("Incorrect use of literal in method invocation");
		// FIXME: the implementation below is problematic!!
		} else if (child instanceof THIS) { // THIS.Identifier.(argulist)
			if (!currentMethod.getType().equals("void"))
				codes.addInstruction("createreturn");
			codes.addInstruction("2createlocal8 "+currentMethod.getLocalSize());
			codes.addInstruction("2getlocal8 "+THIS.this_address);
			codes.addInstruction("2setcalleelocal8 "+THIS.this_address);
			codes.addInstruction("2call8 "+currentMethod.getLabel());
		} else if (child instanceof SUPER) { // SUPER.Identifier.(argulist)
			codes.addInstruction("createreturn");
			codes.addInstruction("2createlocal8 "+currentMethod.getLocalSize());
			codes.addInstruction("2getlocal8 "+THIS.this_address);
			codes.addInstruction("2setcalleelocal8 "+THIS.this_address);
			codes.addInstruction("2call8 "+currentMethod.getLabel());
		} else { // expression.Identifier.(argulist)
			expression e = (expression)child;
			e.generateCode (t, codes);
			codes.addInstruction("createreturn");
			codes.addInstruction("2createlocal8 "+currentMethod.getLocalSize());
			codes.addInstruction("2getlocal8 "+THIS.this_address);
			codes.addInstruction("2setcalleelocal8 "+THIS.this_address);
			codes.addInstruction("2call8 "+currentMethod.getLabel());
		}
	}*/
	public String getName () {
		return "Nonterminal: method_invocation";
	}
}
