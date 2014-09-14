package itransnet_base.tracking.Server.DataEngine.XML;

import java.util.ArrayList;

import itransnet_base.tracking.Server.DataEngine.*;
import itransnet_base.tracking.Utility.*;

import org.xml.sax.*;
import org.apache.xerces.parsers.SAXParser;

public class MapLoader implements ContentHandler, SensorConstants {
    private Map map;
    private String mapFile;
	
    // Data manipulator
    private Road currentRoad;
    private CrossRoad currentCrossRoad;
    private ArrayList roadPairs;
	
    public MapLoader () { roadPairs = new ArrayList(); }
    public MapLoader (Map m) { this(); map = m; }
    public void setFile (String f) { mapFile = f; }

    public void loadMap () {
	System.out.println("Load:"+mapFile);
	try {
	    XMLReader parser = new SAXParser();
	    parser.setContentHandler (this);			
	    //parser.parse (mapFile);
	    parser.parse (new InputSource(getClass().getResourceAsStream(mapFile)));
	    constructNeighbors();
	} catch (Exception e) {
	    e.printStackTrace();
	}
    }
		
    public void characters(char[] text, int start, int length)
	throws SAXException {}
    public void setDocumentLocator(Locator locator) {}
    public void startDocument() {}
    public void endDocument() {}
    public void startPrefixMapping(String prefix, String uri) {}
    public void endPrefixMapping(String prefix) {}
    public void startElement(String namespaceURI, String localName,
			     String qualifiedName, Attributes atts) {
	if(localName.compareTo("road") == 0) {
	    // Road related elements
	    currentRoad = new Road ();
	    int ID = Integer.parseInt(atts.getValue("id"));
	    currentRoad.setID(ID);
	    currentRoad.setName(atts.getValue("name"));
	    try {
		currentRoad.setNumOfCars(Integer.parseInt(atts.getValue("numOfCars")));
	    }catch (Exception e) { currentRoad.setNumOfCars(0); }
	    try {
		if (atts.getValue("type").equals("LIFO"))
		    currentRoad.setType(LIFO_ROAD);
	    } catch (Exception e) { }
	} else if (localName.compareTo("start") == 0) {
	    double x = Double.parseDouble(atts.getValue("x"));
	    double y = Double.parseDouble(atts.getValue("y"));
	    Coordinate c = new Coordinate (x, y);
	    currentRoad.setStart(c);
	} else if (localName.compareTo("end") == 0) {
	    double x = Double.parseDouble(atts.getValue("x"));
	    double y = Double.parseDouble(atts.getValue("y"));
	    Coordinate c = new Coordinate (x, y);
	    currentRoad.setEnd(c);
	} else if (localName.compareTo("sensor") == 0) {
	    // Sensor related elements
	    int ID = Integer.parseInt(atts.getValue("id"));
	    double pos = Double.parseDouble(atts.getValue("pos"));
	    DefaultSensor s = new DefaultSensor(ID);
	    s.setPos(pos);
	    currentRoad.addSensor(s);
	    map.addSensor(s);
	} else if (localName.compareTo("neighbor") == 0) {
	    int ID = Integer.parseInt(atts.getValue("id"));
	    roadPairs.add (new RoadPair(ID, currentRoad.getID()));
	} else if (localName.compareTo("car") == 0) {
	    // Car related elements
	    int ID = Integer.parseInt(atts.getValue("id"));
	    double pos = Double.parseDouble(atts.getValue("pos"));
	    double speed = Double.parseDouble(atts.getValue("speed"));
	    Car c = new Car(ID);

	    c.setAverageSpeed(speed);
	    c.setLastPortionSpeed(speed);
	    c.setInstanceSpeed(speed);
	    c.setPos(pos);
	    c.setRoad(currentRoad);
	    currentRoad.addCar(c);
	} else if (localName.compareTo("crossroad")==0) {
	    // Cross road related elements
	    currentCrossRoad = new CrossRoad();
	} else if (localName.compareTo("start_road")==0) {
	    int ID = Integer.parseInt(atts.getValue("id"));
	    Road found = findRoad (ID);
	    if (found != null)
		found.addStartCrossPoint(currentCrossRoad);
	} else if (localName.compareTo("end_road")==0) {
	    int ID = Integer.parseInt(atts.getValue("id"));
	    Road found = findRoad (ID);
	    if (found != null)
		found.addEndCrossPoint(currentCrossRoad);
	}
    }
		
    public void endElement(String namespaceURI, String localName,
			   String qualifiedName) {
	if (localName.compareTo("road")==0)
	    map.addRoad(currentRoad);
    }

    private void constructNeighbors() {
	for (int i=0; i<roadPairs.size(); i++) {
	    RoadPair p = (RoadPair)roadPairs.get(i);
	    Road r1 = findRoad (p.id1);
	    Road r2 = findRoad (p.id2);
	    if (r1!=null && r2!=null)
		r1.addNeighbor(r2);
	}
    }

    private Road findRoad (int ID) {
	ArrayList roads = map.getRoad();
	for (int i=0; i<roads.size(); i++) {
	    Road found = (Road)roads.get(i);
	    if (found.getID()==ID)
		return found;
	}
	return null;
    }

    public void ignorableWhitespace(char[] text, int start,
				    int length) throws SAXException {}
    public void processingInstruction(String target, String data){}
	public void skippedEntity(String name) {}
}

class RoadPair {
	public int id1, id2;
	
	public RoadPair (int i1, int i2) { id1=i1; id2=i2; }
}
