package pubsub.edl2.receiver.notifier;

import pubsub.edl2.receiver.*;
import pubsub.edl2.*;

import java.util.*;
import java.io.*;
import java.sql.*;

// For use with MySQL and Django
public class SimpleDBEngine {
	private String dbDriver="com.mysql.jdbc.Driver";
	private String dbURL="jdbc:mysql://localhost:3306/psware";
	private String dbUsername="root";
	private String dbPassword="wsnqt405";
	public Connection conn;
	public Statement queryStatement;
	public ResultSet queryResultSet;

	public SimpleDBEngine () {
	}
	public void createConnection () {
		try {
			Class.forName(dbDriver);
			Properties connProperties = new Properties();
			connProperties.put("user", dbUsername);
			connProperties.put("password", dbPassword);
			connProperties.put("autoReconnect", "true");
			conn = DriverManager.getConnection(dbURL, connProperties);
		} catch (Exception ex) {
			ex.printStackTrace();
			try {
				if (conn!=null)
					conn.close();
			} catch (Exception e) {}
		}
	}
	synchronized public void updateDB(String query) {
		Statement stmt=null;
		try {
			stmt = conn.createStatement();
			//System.out.println("(DBEngine) Executing update: "+query);
			stmt.executeUpdate(query);
		} catch (Exception ex) {
			System.out.println("(DBEngine) Exception when executing: "+query);
			ex.printStackTrace();
		} finally {
			try {
				if (stmt!=null)
					stmt.close();
			} catch (Exception ex) { }
		}
	}
	public void executeQuery(String query) {
		queryStatement=null;
		queryResultSet=null;
		try {
			//System.out.println("(DBEngine) Executing query: "+query);
			queryStatement = conn.createStatement();
			queryResultSet = queryStatement.executeQuery(query);
		} catch (Exception ex) {
			ex.printStackTrace();
			closeQuery();
		} 
	}
	public void closeQuery () {
		try {
			if (queryResultSet!=null) {
				queryResultSet.close();
				queryResultSet=null;
			}
		} catch (Exception ex) { }
		try {
			if (queryStatement!=null) {
				queryStatement.close();
				queryStatement=null;
			}
		} catch (Exception ex) { }
	}
	/*public boolean exists(String tableName, Hashtable<String, String> fields) {
		boolean exists=false;
		String query = "select * from "+tableName;
		Enumeration <String> e = fields.keys();
		int i=0;
		while (e.hasMoreElements()) {
			String name = e.nextElement();
			String value = fields.get(name);
			if (i==0) {
				query=query+" where "+name+"=\""+value+"\"";
			} else {
				query=query+" and "+name+"=\""+value+"\"";
			}
			i++;
		}
			
		executeQuery(query);
		try {
			exists = queryResultSet.next();
		} catch (Exception e) {}
		closeQuery();
		return exists;
	}*/
	synchronized public int getIntField(String fieldName, String tableName, String whereClause) {
		int newID=0;
		String query = "select "+fieldName+" from "+tableName;
		if (whereClause.trim()!="")
			query = query+" where "+whereClause;

		executeQuery(query);
		try {
			if (queryResultSet.next()) {
				newID=queryResultSet.getInt(1);
			}
		} catch (Exception e) {}
		closeQuery();
		return newID;
	}
	synchronized public String getStringField(String fieldName, String tableName, String whereClause) {
		String field="";
		String query = "select "+fieldName+" from "+tableName;
		if (whereClause.trim()!="")
			query = query+" where "+whereClause;

		executeQuery(query);
		try {
			if (queryResultSet.next()) {
				field=queryResultSet.getString(1);
			}
		} catch (Exception e) {}
		closeQuery();
		return field;
	}
}
