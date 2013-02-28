package pubsub.edl2.middlend;

import pubsub.edl2.symbols.*;
import java.util.*;

public class statement extends GenericTreeNode {
	public static int labelIdx;
	public statement () {
		createChildren();
	}
	public void generateCode (SymbolTable t, CodeStore codes) throws UndefinedSymbolException,TypeException {
	}
	public String staticTypeCheck (SymbolTable t) throws UndefinedSymbolException, TypeException {
		return null;
	}
	public String createLabel () {
		return "label_"+(labelIdx++);
	}
	public String getContinueLabel () {
		return null;
	}
	public String getBreakLabel () {
		return null;
	}
}
