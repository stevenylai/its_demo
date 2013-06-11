package itransnet_base.tracking.Server.DataEngine;

import itransnet_base.tracking.Utility.SensorConstants;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
/**
 *	AnimatedCar is the class that contains necessary information in order to display
 *	a real car on the screen. It can be viewed as a wrapper class over the class Car
 */
public class AnimatedCar implements SensorConstants
{
	private static final int N=0;
	private static final int NE=1;
	private static final int E=2;
	private static final int SE=3;
	private static final int S=4;
	private static final int SW=5;
	private static final int W=6;
	private static final int NW=7;

	// The mapping to a real car
	private Car realCar;
	// Create an ID for easy searching
	private int ID;

	// The speed that user will see on the screen
	private double animationSpeed;
	
	// The road which the animation car belongs
	private Road road;
	// Car will be driving from source to dest
	private double sourcePos, destPos;
	private double curPos; // curPos is the current position of the animated car
	
	private double truningPos;
	
	private int orient;
	private short direction;
	
	private Sensor destSensor=null;
	private Sensor curSensor=null;
	
	private Map map;
	
	
	// Keep track of the last rendering time and update the curPos for next rendering
	private long lastRenderTime;
	private boolean readyForRender;
	
	// The id of the image that will be used.
	private int imageID;
	
	// Construct
	public AnimatedCar (Car c)
	{
		orient=0;
		imageID=0;
		readyForRender=false;
		realCar = c;
		imageID = ID = c.getID();
		road = c.getRoad();
		curPos = c.getPos();
		
		lastRenderTime = System.currentTimeMillis();
		updateSpeed();
		
		map=new Map();
		map.loadMap("C:/tinyos/cygwin/opt/tinyos-1.x/contrib/iTranSNet/tools/java/itransnet_base/tracking/map.xml");
		updatePos(map);
		updateOrient ();
		c.setAnimatedCar(this);
	}
	
	public int getID() {return ID;}
	public Road getRoad () {return road;}
	public double getPercent () {return curPos;} //(curPos-1.0)/road.getLength();} //whj
	public double getCurPos() {return curPos;}
	public Car getRealCar() { return realCar; }
	
	public int getOrient() { return orient; }
	public int getImageID () { return imageID; }

	public void setImageID (int id) { imageID = id; }

	/**
	 *	This is the main procedure for synchronizing various kinds of attributes with the real car.
	 *	<p>
	 *	This method should be called only when there is any change to the real car so that the
	 *	information will keep synchronized. The method will perform the following tasks:
	 *	1. Update the speed so that it will reflect the real car's speed
	 *	2. Update to position of the car.
	 */
	 /*
	public void updateStatus ()
	{

	}*/
	
	public void updateSpeed()
	{
		animationSpeed = realCar.getAverageSpeed (); //whj
		
		//0.8*realCar.getInstanceSpeed()
		//	+ 0.1*(realCar.getAverageSpeed () + realCar.getLastPortionSpeed ());
	}

	public void updatePos(Map map)
	{
		readyForRender=false;
		// road hasn't been initialized yet
		if (road == null)
		{
			System.out.println("road initializeding-----");		
			curPos = sourcePos  = realCar.getPos();
			destPos = findDest(map);
			road = realCar.getRoad();
			updateOrient ();
		}
		else
		{
			System.out.println("Animated Car pos updating----");	
			System.out.println("realCar.getRoad()="+realCar.getRoad().getID()+";road="+road.getID()+",realCar.getTurnDirection()"+realCar.getTurnDirection());
			
			for(Iterator ite=realCar.getRoad().getNeighbor().iterator();ite.hasNext();){
				System.out.println("Neighbour:"+((Road)ite.next()).getID());	
			}
			
			if (road != realCar.getRoad())
			{
				System.out.println("No road found----");
				
				Road newRoad = realCar.getRoad();
				
				
                //In the target list, find the insertion point
				List acList = newRoad.getAnimatedCar();
				int insertPos = acList.size();											
				for(int i=0; i<acList.size(); i++)
				{
					AnimatedCar ac = (AnimatedCar)acList.get(i);
					// Skip any of the 'fake' car
					if (ac.getRealCar().getRoad()!=newRoad)
						continue;
					// Find a car that is behind the current position. (insert before this car)

					if (newRoad.getDirection()==DIRECTION_BACKWARD && ac.getRealCar().getPos()>curPos)
					{
						insertPos = i;
						break;
					}
					else if (newRoad.getDirection()==DIRECTION_BACKWARD && ac.getRealCar().getPos()<curPos)
					{
						insertPos = i;
						break;
					}
				}
				
				road.removeAnimatedCar(this);
				road = newRoad;
				acList.add(insertPos, this);
				curPos = sourcePos = realCar.getPos();
				
				System.out.println("Before Orient:"+orient+","+this.getRealCar().getTurnDirection());
				
				updateOrient();
				destPos = findDest(map);
				
				
			}
			else
			{
				System.out.println("findDest----");
				
				// Source position is the real car's position
				curPos = sourcePos = realCar.getPos();
				
				destPos = findDest(map);
				/*if (destPos < sourcePos && realCar.getDirection()==DIRECTION_FORWARD)
					destPos = sourcePos;
				else if (destPos > sourcePos && realCar.getDirection()==DIRECTION_BACKWARD)
					sourcePos = destPos;
					*/
				
				
				//Hard code to be refined later to handle change road
				System.out.println("New TEST-------");
				System.out.println("Pos="+realCar.getPos());
				if(realCar.getPos()==0.8064){
					
					
					
					
				}
				
				
				
				
				
				
				
				
				
				
				
				
				
			}

		}
		/*// Real car has changed to a neighboring road
		else if (road != null && road != realCar.getRoad() && road.isNeighbor(realCar.getRoad()))
		{
			Road newRoad = realCar.getRoad();
			List acList = newRoad.getAnimatedCar();
			// Default: insert at last
			int insertPos = acList.size();
			
			// In the target list, find the insertion point
			for(int i=0; i<acList.size(); i++)
			{
				AnimatedCar ac = (AnimatedCar)acList.get(i);
				// Skip any of the 'fake' car
				if (ac.getRealCar().getRoad()!=newRoad)
					continue;
				// Find a car that is behind the current position. (insert before this car)
				if (ac.getRealCar().getPos()<curPos)
				{
					insertPos = i;
					break;
				}
			}
			road.removeAnimatedCar(this);
			road = newRoad;
			acList.add(insertPos, this);
		}
		// Real car has changed to a new road but animation car hasn't reached
		// end of the old road, so set the sourcePos to the end in order to speed up.
		else if (road != null && road != realCar.getRoad() && curPos<road.getLength()-1)
		{
			if (road.getType()==FIFO_ROAD)
				sourcePos = destPos = road.getLength()-1;
			else if (road.getType()==LIFO_ROAD)
				sourcePos = destPos = 1;
			if (curPos<=1) {
					// The car has reached the destition so update the road information
					changeRoad(realCar.getRoad());
					updateOrient();
					curPos = 1.0;
					// When reached the new road update new source & dest as well
					sourcePos = realCar.getPos();
					destPos = findDest();
				}
		}
		else if (road != null && road != realCar.getRoad() && curPos >= road.getLength()-1)
		{
			// The car has reached the destition so update the road information
			changeRoad(realCar.getRoad());
			updateOrient();
			curPos = 1.0;
			// When reached the new road update new source & dest as well
			sourcePos = realCar.getPos();
			destPos = findDest();
			if (destPos < sourcePos && realCar.getDirection()==DIRECTION_FORWARD) destPos = sourcePos;
		}
		// Real car and animation car are on the same road.
		else
		{
			// Source position is the real car's position
			sourcePos = realCar.getPos();
			destPos = findDest();
			if (destPos < sourcePos && realCar.getDirection()==DIRECTION_FORWARD)
				destPos = sourcePos;
			else if (destPos > sourcePos && realCar.getDirection()==DIRECTION_BACKWARD)
				sourcePos = destPos;
		}
		*/
		if(road!=null)
			readyForRender=true;
//		System.out.println("now position is " + curPos + "real car is now in " + realCar.getRoad().getID() +"  " + realCar.getPos() + "fake car is now in " + road.getID());
	}

	public boolean readyForRender ()
	{
		return readyForRender;
	}

	
	
	
	
	
	
	
	
	
	
	
	public void rendered()
	{
		long curTime = System.currentTimeMillis();
		double newPos = curPos;
	
		if(realCar == null)
			return;
		if (realCar.getDirection()==DIRECTION_FORWARD)
		{
			if(curPos<destPos){
				newPos = curPos + (curTime - lastRenderTime)*animationSpeed / 12;
			}
////		special case for link two roads
			else if(curPos==0.9206){
				//change to road 6
				newPos=0.1;			
				destPos=0.945;
				sourcePos=0.1;
				orient=this.E;
				changeRoad (new Road(6));
			
				
				
			}
			
			
			
			else{
				newPos = destPos;
			}
		}
		else
		{	
			if(curPos>destPos)
				newPos = curPos - (curTime - lastRenderTime)*animationSpeed / 12;
			else
				newPos = destPos;
		}

		System.out.println("Pos="+newPos+",curPos="+curPos+",destPos="+destPos);
		curPos = newPos;
		lastRenderTime = curTime;

		if(true)
			return;
	}
	
	public String toString ()
	{
		if(road!= null)
			return "Road:"+road.getID()+" Source:"+sourcePos+" Dest:"+destPos+" CurPos:"+curPos+" Speed:"+animationSpeed;
		else
			return "Road:null"+" Source:"+sourcePos+" Dest:"+destPos+" CurPos:"+curPos+" Speed:"+animationSpeed;
	}
	
	private double findDest(Map map)
	{
		double pos = realCar.getPos();
		
		ArrayList sensor = road.getSensor();		
		if(sensor.size() == 0)
		{
			System.out.println("fatal error, there is no sensor on the road");
			return 0;
		}
		
		// Search for the next sensor which the car will pass by
		Sensor s;
		System.out.println("orient="+orient+";pos="+pos);
		//orient=S;
		
		
//		realCarcurSensor.getAdjectSensorMap().get(Integer.valueOf(realCar.getDirection()));
		Sensor curSensor=realCar.getRoad().getPreviousSensor(realCar.getPos());
		//realCar.setTurnDirection(2);
		System.out.println("------------Special find dest------------");
		
		System.out.println("curSensor:+"+curSensor.getID()+";realCar.getTurnDirection():"+realCar.getTurnDirection());
		System.out.println("curSensor.getAdjectSensorMap():+"+curSensor.getAdjectSensorMap());
		System.out.println("have:+"+curSensor.getAdjectSensorMap().containsKey(Integer.valueOf(realCar.getTurnDirection())));
		
		
		
		if(realCar.getTurnDirection()==DefaultSensor.DIRECTION_L.intValue()||realCar.getTurnDirection()==DefaultSensor.DIRECTION_R.intValue()){
			if(realCar.getTurnDirection()==DefaultSensor.DIRECTION_L.intValue()){
				Integer sensorId=(Integer)(curSensor.getAdjectSensorMap().get(Integer.valueOf(realCar.getTurnDirection())));
				System.out.println("sensorId:+"+sensorId);				
				System.out.println("Map():+"+map);
				
				this.destSensor=Map.defaultMap.getSensor(sensorId.intValue());
				this.curSensor=curSensor;
				
				System.out.println("new destSensor="+destSensor);
				System.out.println("new destSensorm,id="+destSensor.getID());
			}
			
		}
		
		
		
		System.out.println("------------Normal find dest------------");
		System.out.println("orient="+orient+";pos="+pos);		
		switch(orient)
		{
			case N:
			case W:
				for (int i=sensor.size()-1; i>=0; i--)
				{
					s = (Sensor)sensor.get(i);
					if (s.getPos() < pos)
					{
						System.out.println("@@@+N+"+s.getPos());
						return s.getPos(); //whj -1.0;
					}
				}
			break;
			case E:
			case S:
				for (int i=0; i<sensor.size(); i++)
				{
					s = (Sensor)sensor.get(i);
					if (s.getPos() > pos)
					{
						System.out.println("@@@+S+"+s.getPos());
						return s.getPos(); //whj -1.0;
					}
				}

			break;
		}
		
		System.out.println("@@@@@@@@@:+"+realCar.getPos());
		
	
		
		
		
		
		return pos; 
		
		
		
		
		
		
		
		
		
		
		
		
		
		//whj -1.0;
		/*
		if(road.getEndCrossPoint()!=null)
		{
			if (realCar.getDirection()==DIRECTION_FORWARD)
				return road.getLength() - 1;
			else
				return 1;
		}
		else
			// Let the car move out of the road's end
			return road.getLength()+3.0;
			*/
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	private double getCatchUpSpeed()
	{
		// No need to catch up
		if ((curPos>=sourcePos && realCar.getDirection()==DIRECTION_FORWARD)
			||(curPos<=sourcePos && realCar.getDirection()==DIRECTION_BACKWARD))
			return animationSpeed;
		
		double catchUpSpeed = animationSpeed;
		double catchUpTime;
		if (realCar.getDirection()==DIRECTION_FORWARD)
			catchUpTime = (realCar.getRoad().getLength()-realCar.getPos())/animationSpeed;
		else
			catchUpTime = (realCar.getPos())/animationSpeed;
		// Set the catch up time to at least 1/4 second so that car won't suddenly just into another position
		if (catchUpTime <= 250.0)
			catchUpTime = 250.0;
		if (road == realCar.getRoad())
			catchUpSpeed = Math.abs(sourcePos-curPos)/catchUpTime;
		else if (realCar.getDirection()==DIRECTION_FORWARD)
			catchUpSpeed = (sourcePos-curPos+realCar.getPos())/catchUpTime;
		else
			catchUpSpeed = (curPos-sourcePos+realCar.getPos())/catchUpTime;
		if (catchUpSpeed <animationSpeed)
			return animationSpeed;
		else
			return catchUpSpeed;
	}
	private void changeRoad (Road r)
	{
		road.removeAnimatedCar(this);
		road = r;
		r.addAnimatedCar(this);
	}
	private void updateOrient ()
	{
		if(road == null) return;
		
		
		double startX = road.getStart().getX();
		double startY = road.getStart().getY();
		double endX = road.getEnd().getX();
		double endY = road.getEnd().getY();
		
		System.out.println("startX="+startX+",startY="+startY+",endX="+endX+",endY="+endY);
		if(startX==endX)
		{
			if(endY<startY)
			{
				orient = N;
				direction = DIRECTION_BACKWARD;
			}
			else
			{
				orient = S;
				direction = DIRECTION_FORWARD;
			}
		}
		else
		{
			if(endX<startX)
			{
				orient = W;
				direction = DIRECTION_BACKWARD;
			}
			else
			{
				orient = E;
				direction = DIRECTION_FORWARD;
			}
		}
		realCar.setDirection(direction);
		
		System.out.println("Orient:"+orient);
		/*
		double incAngle = ((startY-endY)/(startX-endX));
		
		// Only 4 orientation now.
		if (incAngle >1 && endY<startY)
			orient = N;
		else if (incAngle <=1 && endX>=startX)
			orient = E;
		else if (incAngle >1 && endY>=startY)
			orient = S;
		else if (incAngle <=1 && endX<startX)
			orient = W;
			*/
	}
	
	
	
	
	
	
	public void rendered(Map map)
	{
		
		long curTime = System.currentTimeMillis();
		double newPos = curPos;
	
		//System.out.println("-------realCar.getDirection:"+realCar.getDirection());
		if(realCar == null)
			return;
		if (realCar.getDirection()==DIRECTION_FORWARD || realCar.getDirection()==DIRECTION_BACKWARD)
		{
			if((this.getOrient()==S || this.getOrient()==E ||this.getOrient()==SE||this.getOrient()==SW)
				&& curPos<destPos){
				newPos = curPos + (curTime - lastRenderTime)*animationSpeed / 12;
			}
			if((this.getOrient()==N || this.getOrient()==W ||this.getOrient()==NE||this.getOrient()==NW)
				&& curPos>destPos){
				newPos = curPos - (curTime - lastRenderTime)*animationSpeed / 12;
			}
			
			
			
////		special case for link two roads
/*			else if(curPos>=0.9206){
				//change to road 6
				newPos=0.005;			
				destPos=0.945;
				sourcePos=0.005;
				orient=this.E;
				List RoadLits=map.getRoad();
				
				for(Iterator ite=RoadLits.iterator();ite.hasNext();){
					Road road=(Road)ite.next();
					if(road.getID()==6){
						changeRoad(road);	
						
					}
				}	
					
			}*/		else{
				//newPos = destPos;
			}
			
            if(this.getDestSensor()!=null&& (this.getOrient()==S||this.getOrient()==N||this.getOrient()==E||this.getOrient()==W)){
            	System.out.println("Render---this.getDestSensor()="+this.getDestSensor().getID());
            	System.out.println("this.getRealCar().getTurnDirection()="+this.getRealCar().getTurnDirection());
            	System.out.println("this.getOrient()="+this.getOrient());
            	
            	if(this.getOrient()==N & this.getRealCar().getTurnDirection()== DefaultSensor.DIRECTION_L.intValue()){
            		orient=this.NW;	
            		
            		newPos=this.getCurSensor().getRoad().getEnd().getScaledX()-0.0142;
            		//newPos=this.getCurSensor().getRoad().getEnd().getScaledX()-0.0242;	
            		//newPos=0.3;	
                	sourcePos=newPos;
                	destPos=this.getDestSensor().getPos();
                	truningPos=newPos-0.02;
                	//truningPos=0.28;
            		
                	if(realCar.getRoad().getID()!=this.getDestSensor().getRoad().getID()){
                 		 changeAniminateCarRoad(map,this.getDestSensor().getRoad().getID());
                 	}
                	/*
            		if(realCar.getRoad().getID()==81){
            		List RoadLits=map.getRoad();
                	for(Iterator ite=RoadLits.iterator();ite.hasNext();){
    					Road road=(Road)ite.next();
    					if(road.getID()==41){
    						changeRoad(road);	
    					}
    				}	
            		} 
            		*/           		
            	}
            	
            	
            	
            	
            	if(this.getOrient()==S & this.getRealCar().getTurnDirection()== DefaultSensor.DIRECTION_L.intValue()){
            		orient=this.SE;	
            		
            		newPos=this.getCurSensor().getRoad().getEnd().getScaledX()-0.029;
            		System.out.println("this.getCurSensor().getRoad().getEnd().getScaledX()"+this.getCurSensor().getRoad().getEnd().getScaledX());
            		System.out.println("newPos="+newPos);
            		//Specfic adjust
            		if(this.getCurSensor().getRoad().getID()==102||this.getCurSensor().getRoad().getID()==92){
            		newPos+=0.04;
            		}
            		
            		//newPos=this.getCurSensor().getRoad().getEnd().getScaledX()-0.049;	
            		//newPos=0.001;
            		sourcePos=newPos;
                	destPos=this.getDestSensor().getPos();
                	
                	truningPos=newPos+0.02;
                	//truningPos=newPos+0.04;
                	//truningPos=0.04;
                	
                	if(realCar.getRoad().getID()!=this.getDestSensor().getRoad().getID()){
                		changeAniminateCarRoad(map,this.getDestSensor().getRoad().getID());
                	}
                	/*
            		if(realCar.getRoad().getID()==7){
            		List RoadLits=map.getRoad();
                	for(Iterator ite=RoadLits.iterator();ite.hasNext();){
    					Road road=(Road)ite.next();
    					if(road.getID()==6){
    						changeRoad(road);	
    					}
    				}	
            		}
            		*/
            	}
            	if(this.getOrient()==E & this.getRealCar().getTurnDirection()== DefaultSensor.DIRECTION_L.intValue()){
            		orient=this.NE;	
            		
            		newPos=this.getCurSensor().getRoad().getEnd().getScaledY()-0.005;
            		//newPos=this.getCurSensor().getRoad().getEnd().getScaledY()+0.025;	
            		//newPos=0.97;	
                	sourcePos=newPos;
                	destPos=this.getDestSensor().getPos();
                	
                	truningPos=Math.max(newPos-0.04,this.getDestSensor().getPos()+0.001);
                	//truningPos=0.931;
            		
                	if(realCar.getRoad().getID()!=this.getDestSensor().getRoad().getID()){
               		 changeAniminateCarRoad(map,this.getDestSensor().getRoad().getID());
               	    }
                	
                	/*
            		if(realCar.getRoad().getID()==6){
                	List RoadLits=map.getRoad();
                    for(Iterator ite=RoadLits.iterator();ite.hasNext();){
        					Road road=(Road)ite.next();
        					if(road.getID()==81){
        						changeRoad(road);	
        					}
        			}	
                	}
            		*/
            	}
            	
            	if(this.getOrient()==W & this.getRealCar().getTurnDirection()== DefaultSensor.DIRECTION_L.intValue()){
            		orient=this.SW;	
            		
            		newPos=this.getCurSensor().getRoad().getEnd().getScaledY()+0.0124;
            		//newPos=this.getCurSensor().getRoad().getEnd().getScaledY()+0.0624;	
            		//newPos=0.79;	
                	sourcePos=newPos;
                	destPos=this.getDestSensor().getPos();
                	truningPos=newPos+0.03;
                	//truningPos=0.82;
            		
                	if(realCar.getRoad().getID()!=this.getDestSensor().getRoad().getID()){
                  		 changeAniminateCarRoad(map,this.getDestSensor().getRoad().getID());
                  	}
                	/*
            		if(realCar.getRoad().getID()==41){
                	List RoadLits=map.getRoad();
                    for(Iterator ite=RoadLits.iterator();ite.hasNext();){
        					Road road=(Road)ite.next();
        					if(road.getID()==7){
        						changeRoad(road);	
        					}
        			}	
                	}
            		*/
            	}
            	
            	
            	
            	
            	System.out.println("Final: this.getOrient()="+this.getOrient());
            	
			}
            
            
            if(this.getOrient()==SE && newPos>=truningPos){
            	System.out.println("Turning ENDM,curPos="+newPos+";truningPos="+truningPos+";destPos="+destPos);
            	truningPos=0;
            	orient=this.E;	
            	this.getRealCar().setTurnDirection(DefaultSensor.DIRECTION_F.intValue());
            	this.setDestSensor(null);
            }
            if(this.getOrient()==NE && newPos<=truningPos){
            	System.out.println("Turning ENDM,curPos="+newPos+";truningPos="+truningPos+";destPos="+destPos);
            	truningPos=1;
            	orient=this.N;	
            	this.getRealCar().setTurnDirection(DefaultSensor.DIRECTION_F.intValue());
            	this.setDestSensor(null);
            }
            if(this.getOrient()==NW && newPos<=truningPos){
            	System.out.println("Turning ENDM,curPos="+newPos+";truningPos="+truningPos+";destPos="+destPos);
            	truningPos=1;
            	orient=this.W;	
            	this.getRealCar().setTurnDirection(DefaultSensor.DIRECTION_F.intValue());
            	this.setDestSensor(null);
            }
            if(this.getOrient()==SW && newPos>=truningPos){
            	System.out.println("Turning ENDM,curPos="+newPos+";truningPos="+truningPos+";destPos="+destPos);
            	truningPos=0;
            	orient=this.S;	
            	this.getRealCar().setTurnDirection(DefaultSensor.DIRECTION_F.intValue());
            	this.setDestSensor(null);
            }
		}
		else
		{	
			if(curPos>destPos)
				newPos = curPos - (curTime - lastRenderTime)*animationSpeed / 12;
			else
				newPos = destPos;
		}

		//System.out.println("Pos="+newPos+",curPos="+curPos+",destPos="+destPos);
		curPos = newPos;
		lastRenderTime = curTime;

		if(true)
			return;
	}

	
	private void changeAniminateCarRoad(Map map,int roadId){
		List RoadLits=map.getRoad();
		for(Iterator ite=RoadLits.iterator();ite.hasNext();){
			Road road=(Road)ite.next();
			if(road.getID()==roadId){
				changeRoad(road);	
			}
		}	
	}
	
	
	
	
	
	public Sensor getDestSensor() {
		return destSensor;
	}

	public void setDestSensor(Sensor destSensor) {
		this.destSensor = destSensor;
	}

	public double getTruningPos() {
		return truningPos;
	}

	public void setTruningPos(double truningPos) {
		this.truningPos = truningPos;
	}

	public Sensor getCurSensor() {
		return curSensor;
	}

	public void setCurSensor(Sensor curSensor) {
		this.curSensor = curSensor;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
