package pubsub.edl2.symbols;

import java.io.*;
import java.util.*;

public class ClassEntry extends AbstractSymbol{
	public  boolean isPrimitiveEvent;
	public boolean subscribed;
	private String id;
	private ClassEntry parentClass;
	private Vector parentInterface;

	private boolean finishedClassCheck;

	public Vector <ClassField> fields;
	private Vector methods;
	private int fieldIndex;

	private int subscribeID;
	public static int subscribeIDcount;

	static {
		subscribeIDcount=0;
	}

	public ClassEntry () {
		super();
		fields = new Vector <ClassField> ();
		methods = new Vector();
		fieldIndex=0;
		finishedClassCheck = false;
		subscribed = false;
		isPrimitiveEvent=true;
		this.subscribeID=subscribeIDcount++;
	}
	public ClassEntry(String id) {
		this();
		this.id=id;
		setKey("class_"+id);
	}

	public void generateKey () {
		setKey("class_"+id);
	}
	public void setSubscribed (boolean subscribed) { this.subscribed=subscribed; }
	public boolean subscribed () { return this.subscribed; }
	public int getSubscribeID () { return this.subscribeID; }

	public void addField (ClassField cf) {
		// FIXME: should set the index depending on the type of the field and the type may not be known at this time.
		cf.setIndex(fieldIndex++);
		fields.add(cf);
	}
	public boolean typeCheck () throws TypeException, UndefinedSymbolException{
		if (!finishedClassCheck) {
			for (int i=0; i<fields.size(); i++) {
				ClassField cf = fields.get(i);
				cf.typeCheck();
			}
			finishedClassCheck = true;
		}
		// FIXME: need to check the methods in the interfaces are implemented
		return true;
	}
	public void addMethod (ClassMethod cm) {
		methods.add(cm);
	}
	public int getAllocateSize () { return this.fieldIndex; }
	public String getID () { return id; }
	public Vector getMethods () { return methods; }
	public ClassEntry getParentClass () { return parentClass; }
}
