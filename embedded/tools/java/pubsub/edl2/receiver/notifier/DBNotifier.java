package pubsub.edl2.receiver.notifier;

import pubsub.edl2.receiver.*;
import pubsub.edl2.*;

import java.util.*;
import java.io.*;
import java.sql.*;

public class DBNotifier implements Runnable, EventNotifier {
	public SimpleDBEngine db;
	int version=0;
	MainComposite compiler;
	EventReceiver receiver;

	public DBNotifier () {
		db = new SimpleDBEngine();
		db.createConnection();
		resetTable();
	}
	public void resetTable() {
		version=0;
		db.updateDB("update sub_subscription set version="+version);
		// Careful with the foreign keys here ...
		db.updateDB("delete from pub_eventinstanceattribute");
		db.updateDB("delete from pub_eventinstance");
		db.updateDB("delete from pub_eventmetaattribute");
		db.updateDB("delete from pub_eventmeta");
	}
	public void notify(EventInstanceInfo e) {
		int subID, instanceID, attributeID;

		// Update EventMeta (if necessary)
		if (db.getIntField("count(*)", "pub_eventmeta", "")==0) {
			subID=1;
			db.updateDB("insert into pub_eventmeta values ("+subID+", \""+e.meta.ID+"\")");
		} else if (db.getIntField("count(*)", "pub_eventmeta", "eventName=\""+e.meta.ID+"\"")==0) {
			subID = db.getIntField("max(id)", "pub_eventmeta", "")+1;
			db.updateDB("insert into pub_eventmeta values ("+subID+", \""+e.meta.ID+"\")");
		} else {
			subID = db.getIntField("id", "pub_eventmeta", "eventName=\""+e.meta.ID+"\"");
		}

		// Insert EventInstance
		if (db.getIntField("count(*)", "pub_eventinstance", "")==0) {
			instanceID=1;
		} else {
			instanceID = db.getIntField("max(id)", "pub_eventinstance", "")+1;
		}
		db.updateDB("insert into pub_eventinstance values ("+instanceID+", "+subID+", now())");

		for (int i=0; i<e.meta.fields.size(); i++) {
			String attributeName=e.meta.fields.get(i);
			int attributeValue=e.data[i];

			// Update EventMetaAttribute (if necssary)
			if (db.getIntField("count(*)", "pub_eventmetaattribute",
				"subID_id="+subID)==0) {

				attributeID=1;

				db.updateDB("insert into pub_eventmetaattribute values ("
					+attributeID+", "+subID+", \""+attributeName+"\")");

			} else if (db.getIntField("count(*)", "pub_eventmetaattribute",
				"subID_id="+subID+" and attributeName=\""+attributeName+"\"")==0) {

				attributeID = db.getIntField("max(id)", "pub_eventmetaattribute",
					"subID_id="+subID)+1;

				db.updateDB("insert into pub_eventmetaattribute values ("
					+attributeID+", "+subID+", \""+attributeName+"\")");
			} else {
				attributeID = db.getIntField("id", "pub_eventmetaattribute",
					"subID_id="+subID+" and attributeName=\""+attributeName+"\"");
			}

			// Insert EventInstanceAttribute
			int newID;
			if (db.getIntField("count(*)", "pub_eventinstanceattribute", "")==0) {
				newID=1;
			} else {
				newID=db.getIntField("max(id)", "pub_eventinstanceattribute", "")+1;
			}
			db.updateDB("insert into pub_eventinstanceattribute values ("
				+newID+", "+instanceID+", "+attributeID+", "+attributeValue+")");
		}
	}
	public void checkUpdate () {
		int version = db.getIntField("version", "sub_subscription", "");
		//System.out.println("Checking DB for update, current version: "+version);
		if (version>this.version) {
			String sub=db.getStringField("sub", "sub_subscription", "version="+version);
			System.out.println("New subscription received:\n"+sub);

			EventBuffer buffer = new EventBuffer();
			buffer.notifiers.add(this);
			if (receiver!=null)
				receiver.notifiers.clear();
			receiver=new EventReceiver();
			receiver.notifiers.add(buffer);
			compiler=new MainComposite();
			MainComposite.version++;
			compiler.receiver=receiver;
			compiler.compile(new StringReader(sub));
			this.version=version;
		}
		gc();
	}
	public void gc() {
		db.updateDB("delete pub_eventinstanceattribute from pub_eventinstanceattribute, pub_eventinstance where pub_eventinstanceattribute.instanceID_id=pub_eventinstance.id and TIMEDIFF(date_sub(now(), INTERVAL 1 MINUTE), pub_eventinstance.pubTime)>0");
		db.updateDB("delete from pub_eventinstance where TIMEDIFF(date_sub(now(), INTERVAL 1 MINUTE), pub_eventinstance.pubTime)>0");
	}
	public void run () {
		while (true) {
			try {
				checkUpdate();
				Thread.sleep(1000);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	public static void main(String[] args) throws Exception {
		DBNotifier n = new DBNotifier();
		Thread t = new Thread(n);
		t.start();
	}
}
