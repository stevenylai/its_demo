package pubsub.edl2.symbols;

public class SymbolRedeclarationException extends Exception {
	public SymbolRedeclarationException(AbstractSymbol sym) {
		System.out.println("Symbol: "+sym+" has already been declared.");
	}
}
