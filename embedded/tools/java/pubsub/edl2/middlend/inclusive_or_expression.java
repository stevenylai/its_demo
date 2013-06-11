package pubsub.edl2.middlend;


import java.util.*;

public class inclusive_or_expression extends expression {
	String oper;
	public inclusive_or_expression() {
		createChildren();
	}
	public inclusive_or_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: inclusive_or_expression";
		else
			return "Nonterminal: inclusive_or_expression "+oper;
	}
	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException {
		expression e1 = (expression)children.get(0);
		expression e2 = (expression)children.get(1);
		e1.constructTable(t);
		e2.constructTable(t);
	}*/
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		expression e1 = (expression)children.get(0);
		expression e2 = (expression)children.get(1);
		String type1 = e1.staticTypeCheck (t);
		String type2 = e2.staticTypeCheck (t);
		if (!TypeInfo.typeMatch(type1,type2)) {
			throw new TypeException ("Type mismatch of "+type1+" and "+type2);
		} else if (!TypeInfo.typeMatch(type1,"boolean")) {
			throw new TypeException ("Type error of type: "+type1+", expected: boolean");
		} else
			return type1;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		expression e1 = (expression)children.get(0);
		expression e2 = (expression)children.get(1);
		e1.generateCode(t, codes);
		e2.generateCode(t, codes);
		codes.addInstruction("lor");
	}*/
}
