package pubsub.edl2.middlend;

import java.util.*;

public class THIS extends expression {
	// 'this' is a variable available to every function at the following address:
	public static final int this_address = 0;
	public THIS() {
		createChildren();
	}
	/*public void generateCode (SymbolTable t, CodeStore codes) {
		//instructions.add("getlocal "+this_address);
	}*/
	public String getName () {
		return "Nonterminal: THIS";
	}
}
