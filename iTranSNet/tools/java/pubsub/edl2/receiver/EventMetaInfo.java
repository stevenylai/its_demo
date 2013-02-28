package pubsub.edl2.receiver;

import java.util.*;

public class EventMetaInfo {
	static final public short EVENT_META_UPDATE=0;
	static final public short EVENT_META_DELETE=1;
	static final public short EVENT_META_SUBSCRIBE=2;
	public String ID;
	public ArrayList <String> fields;
	public short subID;
	public short lifetime;
	public short rate;
	public short length;
	public short type;

	public EventMetaInfo () {
		fields = new ArrayList <String> ();
	}
	public int getType(int idx) {
		int mask=0xff>>idx;
		/*System.out.println("Mask: "+Integer.toHexString(mask)
				+", type&mask: "+Integer.toHexString(type&mask)
				+", real type: "+Integer.toHexString((type&mask)>>(8-idx-1)));*/
		return (type&mask)>>(8-idx-1);
	}
	public boolean isSubscribed() {
		int value=getType(0);
		if (value==0)
			return false;
		else
			return true;
	}
	public boolean isComposite() {
		int value=getType(1);
		if (value==0)
			return false;
		else
			return true;
	}
	public boolean isAggregate() {
		int value=getType(2);
		if (value==0)
			return false;
		else
			return true;
	}
	public void printType () {
		String typeStr="Type code: "+Integer.toHexString(type)+".";
		for (int i=0; i<2; i++) {
			typeStr=typeStr+" ("+i+"): "+Integer.toHexString(getType(i));
		}
		//System.out.println(typeStr);
	}
	public String toString () {
		String str="EventMeta ("+subID+"), length: "+length;
		if (fields.size()>0) {
			str=str+", fields: ";
			for (int i=0; i<fields.size(); i++) {
				if (i<fields.size()-1) {
					str=str+fields.get(i)+", ";
				} else {
					str=str+fields.get(i);
				}
			}
		}
		return str;
	}
}
