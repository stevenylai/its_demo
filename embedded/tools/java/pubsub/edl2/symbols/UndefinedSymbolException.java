package pubsub.edl2.symbols;

public class UndefinedSymbolException extends Exception {
	public UndefinedSymbolException(AbstractSymbol sym) {
		System.out.println("Symbol: "+sym+" has not been declared.");
	}
	public UndefinedSymbolException (String errorInfo) {
		System.out.println(errorInfo);
	}
}
