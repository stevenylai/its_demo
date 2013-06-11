package pubsub.edl2.symbols;

import java.io.*;
import java.util.*;

public class ClassField extends Variable implements Cloneable {

	public ClassField () {
		super();
	}
	public ClassField (String id) {
		super(id);
	}

	//public String getInstruction () {
		//return "2getheap8 "+getIndex();
	//}
	public String setInstruction () {
		//return "2setheap8 "+getIndex();
		return getID();
	}
	public boolean isStatic() {
		return false;
	}
	public Object clone () throws CloneNotSupportedException {
		ClassField copy=(ClassField)super.clone();
		return copy;
	}
}
