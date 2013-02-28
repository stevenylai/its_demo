package pubsub.edl2.symbols;

public class TypeException extends Exception {
	public TypeException(AbstractSymbol sym) {
		System.out.println("Symbol: "+sym+" has invalid type information");
	}
	public TypeException(String errorInfo) {
		System.out.println(errorInfo);
	}
}

