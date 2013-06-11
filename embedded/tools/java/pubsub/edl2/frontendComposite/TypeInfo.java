package pubsub.edl2.frontendComposite;

import java.io.*;
import java.util.*;

public class TypeInfo {
	public static boolean isPrimitiveType (String t) {
		// FIXME: more types need to be supported
		return t.equals("int")||t.equals("boolean");
	}
	// FIXME: need to handle type conversion
	public static boolean typeMatch (String type1, String type2) {
		if (type1!=null && type2!=null)
			return type1.equals(type2);
		else
			return false;
		/*
		if (isPrimitiveType(type1) || isPrimitiveType(type2)) {
			return type1.equals(type2);
		}*/
	}
}
