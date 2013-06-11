package pubsub.edl2.symbols;

import java.io.*;
import java.util.*;

public class MethodParameter extends Variable {
	public MethodParameter () {
		super();
	}
	public MethodParameter (String id) {
		super(id);
	}
	public String getInstruction () {
		return "2getparameter8 "+getIndex();
	}
	public String setInstruction () {
		return "2setparameter8 "+getIndex();
	}
				/* Useless...
	private ClassMethod belongto;


	public void setMethod(ClassMethod belongto) { this.belongto=belongto; }
	public ClassMethod getMethod () { return this.belongto; }*/
}
