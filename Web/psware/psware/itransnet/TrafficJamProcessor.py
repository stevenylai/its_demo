class TrafficJamTemplate:
	template = """event System {
	int carID;
	int roadID;
	int posID;
	int status;
}
event TrafficJam {
	int id=System.carID;
	int roadID=System.roadID;
	int posID=System.posID;
	int status=System.status;
} where {
	@WHERE@
}
subscribe TrafficJam;"""

	event=""
	where = ""
	def __init__(self):
		self.event=""
		self.where=""
	def generateEDL(self):
		self.event=''+TrafficJamTemplate.template
		#return self.event.replace("@WHERE@", self.where)
		return self.event.replace("@WHERE@", "roadID>0")
class CarEvent:
	carID=0
	roadID=0
	posID=0
	status=0
	def __init__(self, carID=0, roadID=0, posID=0, status=0):
		self.carID=carID
		self.roadID=roadID
		self.posID=posID
		self.status=status
	def __cmp__(self, other):
		return self.carID-other.carID
	def __str__(self):
		return 'Car ID: '+str(self.carID)+', road: '+str(self.roadID)+', pos: '+str(self.posID)+', status: '+str(self.status)
class RoadEvent:
	roadID=0
	carList=None
	def __init__(self):
		self.roadID=0
		self.carList=[]
	def addCar(self, newCar):
		if newCar.status==TrafficJamDetector.STATUS_FREE:
			#print 'Road', self.roadID, 'Adding car:', str(newCar)
			self.carList.append(newCar)
	def getCount(self):
		return len(self.carList)
	def __str__(self):
		return 'Road '+str(self.roadID)+". No. of cars: "+str(len(self.carList))
class TrafficJamDetector:
	carList=None
	subList=None
	roadList=None
	threshold=0
	STATUS_FREE=1
	STATUS_COLLISION=2
	map={
	0:(4, 3, 1, 1),
	1:(1, 3, 2, 1),
	2:(2, 3, 3, 1),
	3:(3, 3, 5, 1),
	4:(6, 4, 1, 2),
	5:(7, 4, 2, 2),
	6:(8, 4, 3, 2),
	7:( 9, 4, 5, 2),
	8:(6, 3, 7, 1),
	9:(7, 3, 8, 1),
	10:(8, 3, 9, 1) }
	def __init__(self):
		self.carList=[]
		self.subList=[]
		self.threshold=0
	def getPub(self):
		self.roadList=[]
		for sub in self.subList:
			r=RoadEvent()
			r.roadID=sub
			self.roadList.append(r)
		self.calculatePub()
		return self.generatePub()
	def putToRoad(self, car):
		for k,v in TrafficJamDetector.map.items():
			if (v[0]==car.roadID and v[1]==car.posID) or (v[2]==car.roadID and v[3]==car.posID):
				#print ('Found road '+str(k)+' to add')
				for r in self.roadList:
					if r.roadID==k:
						self.removeCar(car)
						r.addCar(car)
						return
				return
	def removeCar(self, car):
		for r in self.roadList:
			if r.carList.count(car)>0:
				#print ('Road', r.roadID, 'Removing car:', car)
				r.carList.remove(car)
				return
	def calculatePub (self):
		for car in self.carList:
			self.putToRoad(car)
	def generatePub (self):
		allStr=''
		for pub in self.roadList:
			if pub.getCount()>=self.threshold:
				allStr=allStr+str(pub.roadID)+', '
		return allStr
if __name__ == "__main__":
	detector=TrafficJamDetector()

	#Add cars
	detector.carList.append(CarEvent(6, 6, 3, 2))

	#Add threshold
	detector.threshold=1

	#Add subscriptions
	detector.subList=[1,2,3,4,7,8,9,6,5,10,0]

	print (detector.getPub())

	for r in detector.roadList:
		print (r,"|",)
