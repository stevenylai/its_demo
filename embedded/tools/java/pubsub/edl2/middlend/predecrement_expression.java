package pubsub.edl2.middlend;


import java.util.*;

public class predecrement_expression extends expression {
	String oper;
	public predecrement_expression() {
		createChildren();
	}
	public predecrement_expression (String oper) {
		this(); this.oper=oper;
	}
	public String getName () {
		if (oper==null)
			return "Nonterminal: predecrement_expression";
		else
			return "Nonterminal: predecrement_expression "+oper;
	}
	/*public void constructTable (SymbolTable t) throws SymbolRedeclarationException {
		expression e1 = (expression)children.get(0);
		e1.constructTable(t);
	}*/
	/*public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		expression e1 = (expression)children.get(0);
		String type1 = e1.staticTypeCheck(t);
		if (!TypeInfo.typeMatch(type1,"int")) {
			throw new TypeException ("Type error of type: "+type1);
		} else
			return type1;
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
		expression e1 = (expression)children.get(0);
		e1.removeNormalAttribute ("leftvalue");
		e1.generateCode(t, codes);
		codes.addInstruction("copy");
		codes.addInstruction("2pushc10 1");
		codes.addInstruction("sub");
		e1.addNormalAttribute ("leftvalue", new Boolean(true));
		e1.generateCode(t, codes);
		codes.addInstruction("pop"); // discard the unwanted value
	}*/
}
