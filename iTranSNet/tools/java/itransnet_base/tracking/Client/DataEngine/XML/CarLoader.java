package itransnet_base.tracking.Client.DataEngine.XML;

import java.util.ArrayList;

import org.xml.sax.*;
import org.apache.xerces.parsers.SAXParser;

// Server's modules
import itransnet_base.tracking.Server.DataEngine.*;

// Client's modules
import itransnet_base.tracking.Client.DataEngine.*;

public class CarLoader implements ContentHandler
{
	// Target file for loading the cars
	private volatile String targetFile;
	// XML parser
	private XMLReader parser;
	// list of car maintained internally
	private ArrayList carList;
	private int roadID;

	public CarLoader (String targetFile)
	{
		this.targetFile = targetFile;
		try {
			parser = new SAXParser();
			parser.setContentHandler (this);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public ArrayList getCarList ()
	{
		carList = new ArrayList();
		boolean fileread = false;
		while (!fileread)
		{
			try {
				// Reestablish the list
				parser.parse (targetFile);
				fileread=true;
			}
			catch (Exception e)
			{
				System.out.println("Server busy! Retrying...");
			}
		}
		return carList;
	}
	
	public void startElement(String namespaceURI, String localName,
	 String qualifiedName, Attributes atts)
	{
		if (localName.compareTo("road")==0)
		{
			// Set the current road
			roadID = Integer.parseInt(atts.getValue("id"));
		}
		else if (localName.compareTo("car")==0)
		{
			// Add a car to the list
			SimpleCar c = new SimpleCar();
			c.setRoadID (roadID);
			c.setID(Integer.parseInt(atts.getValue("id")));
			c.setPos(Double.parseDouble(atts.getValue("pos")));
			c.setSpeed(Double.parseDouble(atts.getValue("speed")));
			carList.add(c);
		}
	}

	public void endElement(String namespaceURI, String localName,
	 String qualifiedName)
	{}

	public void ignorableWhitespace(char[] text, int start,
	 int length) throws SAXException {}
	public void processingInstruction(String target, String data){}
	public void skippedEntity(String name) {}
	public void characters(char[] text, int start, int length)
	 throws SAXException {}
	public void setDocumentLocator(Locator locator) {}
	public void startDocument() {}
	public void endDocument() {}
	public void startPrefixMapping(String prefix, String uri) {}
	public void endPrefixMapping(String prefix) {}
}