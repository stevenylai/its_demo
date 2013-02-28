package pubsub.edl2.middlend;


import java.util.*;

public class assignment extends expression {
	public assignment() {
		createChildren();
	}
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		expression e2 = (expression)children.get(2); // assignment_expression (right value)
		String rightType = e2.staticTypeCheck (t);
		String leftType = null;
		Object child = children.get(0); // postfix_expression (left value)
		if (child instanceof name) {
			name nm = (name)child;
			nm.addNormalAttribute("leftvalue", new Boolean(true));
			leftType = nm.staticTypeCheck(t);
		} else if (child instanceof Literal) {
			throw new TypeException("Inappropriate literal as left value");
		} else if (child instanceof THIS) {
			throw new TypeException("Inappropriate 'this' as left value");
		} else if (child instanceof field_access) {
			field_access fa = (field_access)child;
			fa.addNormalAttribute("leftvalue", new Boolean(true));
			leftType = fa.staticTypeCheck(t);
		} else if (child instanceof method_invocation) {
			throw new TypeException("Inappropriate method invocation as left value");
		} else if (child instanceof expression) {
			throw new TypeException("Inappropriate expression as left value");
		}
		if (TypeInfo.typeMatch(leftType,rightType))
			return leftType;
		else {
			throw new TypeException("Type mismatch for "+leftType+" and "+rightType);
		}
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		expression e2 = (expression)children.get(2); // assignment_expression (right value)
		e2.generateCode (t, codes);
		Object child = children.get(0); // postfix_expression (left value)
		if (child instanceof name) {
			name nm = (name)child;
			nm.generateCode(t, codes);
		} else if (child instanceof Literal) {
			throw new TypeException("Inappropriate literal as left value");
		} else if (child instanceof THIS) {
			throw new TypeException("Inappropriate 'this' as left value");
		} else if (child instanceof field_access) {
			field_access fa = (field_access)child;
			fa.generateCode (t, codes);
		} else if (child instanceof method_invocation) {
			throw new TypeException("Inappropriate method invocation as left value");
		} else if (child instanceof expression) {
			throw new TypeException("Inappropriate expression as left value");
		}
		// FIXME: need to differentiate between different types of operators
		// children.get(1); // assignment_operator
	}*/
	public String getName () {
		return "Nonterminal: assignment";
	}
}
