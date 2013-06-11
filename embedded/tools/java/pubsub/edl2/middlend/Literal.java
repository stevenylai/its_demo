package pubsub.edl2.middlend;

import java.util.*;

public class Literal extends expression {
	public static final int INTEGER=0;
	public static final int BOOLEAN=1;
	public static final int NULL=2;
	private int type;
	public String literal;
	public Literal() {
		createChildren();
	}
	public Literal(int type, String literal) {
		this();
		this.type=type;
		this.literal=literal;
	}
	public String getType() {
		switch (type) {
			case 0:
				return "int";
			case 1:
				return "boolean";
			case 2:
				return "null";
		}
		return null;
	}
	/*
	public void generateCode (SymbolTable t, CodeStore codes) {
		codes.addInstruction(literal);
		if (type==INTEGER)
			codes.addInstruction("2pushc10 "+literal);
		else if (type==BOOLEAN && literal.equals("true"))
			codes.addInstruction("2pushc10 1");
		else if (type==BOOLEAN && literal.equals("false"))
			codes.addInstruction("2pushc10 0");
	}
	public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		switch (type) {
			case 0:
				return "int";
			case 1:
				return "boolean";
			case 2:
				return "null";
		}
		return null;
	}*/
	public String getName () {
		switch (type) {
			case 0:
				return "Integer Literal: "+literal;
			case 1:
				return "Boolean Literal: "+literal;
			case 2:
				return "Null Literal: "+literal;
		}
		return "Unknown Literal";
	}
}
