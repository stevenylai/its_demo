package itransnet_base.tracking.Server.DataEngine.XML;

import org.apache.xerces.parsers.*;
import org.apache.xerces.dom.*;
import org.w3c.dom.*;

import java.util.ArrayList;
import java.util.List;
import java.io.*;

import itransnet_base.tracking.Server.DataEngine.*;
import itransnet_base.tracking.Utility.*;

public class MapDumper
{
	private Map map;
	private String outputFile;
	private Document doc;
	FileWriter fw;
	
	public MapDumper (Map map)
	{
		this.map = map;
		outputFile = "dump.xml";
	}
	
	public void setDumpFile (String file) { outputFile = file; }
	public void dump()
	{
		// To hold the list of cross roads
		ArrayList crossRoads = new ArrayList();
		
		// Initialize the document with root element <map>
		DOMImplementation di = new DOMImplementationImpl ();
		doc = di.createDocument (null, "map", null);
		Element root = doc.getDocumentElement();
		
		// Map: road
		ArrayList roads = map.getRoad();
		for (int i=0; i<roads.size(); i++)
		{
			Road r = (Road)roads.get(i);
			Element re = doc.createElement("road");
			root.appendChild(re);
			
			// Road: ID & name
			re.setAttribute("id", Integer.toString(r.getID()));
			re.setAttribute("name", r.getName());
			re.setAttribute("numOfCars", Integer.toString(r.getNumOfCars()));
			
			// Road: start & end
			Coordinate start = r.getStart();
			Coordinate end = r.getEnd();
			
			// Start: x & y
			Element startElement = doc.createElement("start");
			startElement.setAttribute("x", Double.toString(start.getX()));
			startElement.setAttribute("y", Double.toString(start.getY()));
			re.appendChild(startElement);
			
			// End: x & y
			Element endElement = doc.createElement("end");
			endElement.setAttribute("x", Double.toString(end.getX()));
			endElement.setAttribute("y", Double.toString(end.getY()));
			re.appendChild(endElement);
			
			// Road: numOfCars
			Element numElement = doc.createElement("numOfCars");
			numElement.setAttribute("x", Integer.toString(r.getNumOfCars()));
			re.appendChild(numElement);
			
			// Road: sensor
			ArrayList sensors = r.getSensor();
			for(int j=0; j<sensors.size(); j++)
			{
				// Sensor: id & pos
				Sensor s = (Sensor)sensors.get(j);
				Element se = doc.createElement("sensor");
				se.setAttribute("id", Integer.toString(s.getID()));
				se.setAttribute("pos", Double.toString(s.getPos()));
				re.appendChild(se);
			}
			
			// Road: car
			List cars = r.getCar();
			for(int j=0; j<cars.size(); j++)
			{
				// Car: id, pos & speed
				Car c = (Car)cars.get(j);
				Element ce = doc.createElement("car");
				ce.setAttribute("id", Integer.toString(c.getID()));
				ce.setAttribute("pos", Double.toString(c.getPos()));
				ce.setAttribute("speed", Double.toString(c.getInstanceSpeed()));
				re.appendChild(ce);
			}
			
			ArrayList neighbor = r.getNeighbor();
			// Road: Neighbor
			for(int j=0; j<neighbor.size(); j++)
			{
				Road nr = (Road)neighbor.get(j);
				Element ne = doc.createElement("neighbor");
				ne.setAttribute("id", Integer.toString(nr.getID()));
				re.appendChild(ne);
			}
			
			// Add cross road if necessary
			CrossRoad cr = r.getEndCrossPoint ();
			if (cr!=null && !crossRoads.contains(cr))
				crossRoads.add(cr);
			cr = r.getStartCrossPoint ();
			if (cr!=null && !crossRoads.contains(cr))
				crossRoads.add(cr);
		}
		
		// Crossroad
		for (int i=0; i<crossRoads.size(); i++)
		{
			CrossRoad cr = (CrossRoad)crossRoads.get(i);
			Element cre = doc.createElement ("crossroad");
			root.appendChild(cre);
			
			// Crossroad: start
			ArrayList startRoad = cr.getStartList();
			for(int j=0; j<startRoad.size(); j++)
			{
				Road r = (Road)startRoad.get(j);
				Element re = doc.createElement ("start_road");
				re.setAttribute("id", Integer.toString(r.getID()));
				cre.appendChild(re);
			}

			// Crossroad: end
			ArrayList endRoad = cr.getEndList();
			for(int j=0; j<endRoad.size(); j++)
			{
				Road r = (Road)endRoad.get(j);
				Element re = doc.createElement ("end_road");
				re.setAttribute("id", Integer.toString(r.getID()));
				cre.appendChild(re);
			}
		}
		
		try {
			writeFile();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	} // end of dump()
	
	private void writeFile() throws IOException
	{
		fw = new FileWriter(outputFile);
		fw.write("<?xml version=\"1.0\"?>\n");
		
		Element root = doc.getDocumentElement();
		traverseNode(root);
		fw.close();
	}
	
	private void traverseNode(Node node) throws IOException
	{
		if(node.getNodeType() == Node.ELEMENT_NODE)
		{
			// Start tag
			fw.write("<"+node.getNodeName());
			
			// Attributes
			NamedNodeMap attribs = node.getAttributes();
			for(int i=0; i<attribs.getLength(); i++)
			{
				fw.write(" "+attribs.item(i).getNodeName());
				fw.write("=\"" +attribs.item(i).getNodeValue()+"\"");
			}
			fw.write(">\n");
			
			// Child elements
			NodeList children = node.getChildNodes();
			for (int i=0; i<children.getLength(); i++)
				traverseNode(children.item(i));
			
			// End tag
			fw.write("</"+node.getNodeName()+">\n");
		}
	}
} // end of class mapDumper
