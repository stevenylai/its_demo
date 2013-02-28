#ifndef TRACKING_LIB
#define TRACKING_LIB

#define TOTAL_ROADS 20
#define TOTAL_INTERSECTIONS 15
#define TOTAL_CARS 32
#define MAX_CARS_PER_ROAD 10
#define MAX_QUEUES_PER_INTER 4
#define MAX_CARS_PER_INTER 3

#define INVALID_ID 0
#define CLISSIONSTATUS_FREE 1
#define CLISSIONSTATUS_CLISSION	2

typedef struct car {
	uint8_t id;
	uint8_t inter_id;
	uint8_t junction;
	uint8_t status;
	struct road * currentRoad;
	struct intersection * currentIntersection;
}Car;
typedef struct road {
	struct intersection * start;
	uint8_t startJunct;
	struct intersection * end;
	uint8_t endJunct;
	Car * cars[MAX_CARS_PER_ROAD];
}Road;
typedef struct intersection {
	uint8_t id;
	Road * endRoads[MAX_QUEUES_PER_INTER];
	Road * startRoads[MAX_QUEUES_PER_INTER];
	Car * cars[MAX_QUEUES_PER_INTER][MAX_CARS_PER_INTER];
}Intersection;
typedef struct map {
	Intersection intersections [TOTAL_INTERSECTIONS];
	Road roads [TOTAL_ROADS];
	Car cars[TOTAL_CARS];
}TrackingMap;

Intersection * getIntersectionByID(uint8_t inter_id, struct map *mapPtr) {
	uint8_t i;
	for (i=0; i<TOTAL_INTERSECTIONS; i++) {
		if (mapPtr->intersections[i].id==inter_id) {
			return &(mapPtr->intersections[i]);
		}
	}
	return NULL;
}
void interConnect(struct map * mapPtr) {
	uint8_t i;
	for (i=0; i<TOTAL_ROADS; i++) {
		if (mapPtr->roads[i].start==NULL || mapPtr->roads[i].end==NULL)
			break;

		if (mapPtr->roads[i].end!=NULL) {
			mapPtr->roads[i].end->endRoads[mapPtr->roads[i].endJunct-1]=&(mapPtr->roads[i]);
		}

		if (mapPtr->roads[i].start!=NULL) {
			mapPtr->roads[i].start->startRoads[mapPtr->roads[i].startJunct-1]=&(mapPtr->roads[i]);
		}
	}
}
void initialMap(struct map * mapPtr) {
	uint8_t i, j, k;
	// Reset cars
	for (i=0; i<TOTAL_CARS; i++) {
		mapPtr->cars[i].id=INVALID_ID;
	}
	// Reset intersection
	for (i=0; i<TOTAL_INTERSECTIONS; i++) {
		mapPtr->intersections[i].id=INVALID_ID;
		for (j=0; j<MAX_QUEUES_PER_INTER; j++) {
			mapPtr->intersections[i].endRoads[j]=mapPtr->intersections[i].startRoads[j]=NULL;
			for (k=0; k<MAX_CARS_PER_INTER; k++)
				mapPtr->intersections[i].cars[j][k]=NULL;
		}
	}
	// Reset roads
	for (i=0; i<TOTAL_ROADS; i++) {
		mapPtr->roads[i].start=mapPtr->roads[i].end=NULL;
		mapPtr->roads[i].startJunct=mapPtr->roads[i].endJunct=INVALID_ID;
		for (j=0; j<MAX_CARS_PER_ROAD; j++) {
			mapPtr->roads[i].cars[j]=NULL;
		}
	}

	// Intersections
	for (i=0; i<9; i++)
		mapPtr->intersections[i].id=i+1;
	mapPtr->intersections[9].id=15;
	mapPtr->intersections[10].id=16;
	mapPtr->intersections[11].id=17;

	// Roads
	mapPtr->roads[0].start=getIntersectionByID(4, mapPtr);
	mapPtr->roads[0].startJunct=2;
	mapPtr->roads[0].end=getIntersectionByID(6, mapPtr);
	mapPtr->roads[0].endJunct=1;

	mapPtr->roads[1].start=getIntersectionByID(6, mapPtr);
	mapPtr->roads[1].startJunct=3;
	mapPtr->roads[1].end=getIntersectionByID(7, mapPtr);
	mapPtr->roads[1].endJunct=1;

	mapPtr->roads[2].start=getIntersectionByID(7, mapPtr);
	mapPtr->roads[2].startJunct=3;
	mapPtr->roads[2].end=getIntersectionByID(8, mapPtr);
	mapPtr->roads[2].endJunct=1;

	mapPtr->roads[3].start=getIntersectionByID(8, mapPtr);
	mapPtr->roads[3].startJunct=3;
	mapPtr->roads[3].end=getIntersectionByID(9, mapPtr);
	mapPtr->roads[3].endJunct=1;

	mapPtr->roads[4].start=getIntersectionByID(1, mapPtr);
	mapPtr->roads[4].startJunct=2;
	mapPtr->roads[4].end=getIntersectionByID(6, mapPtr);
	mapPtr->roads[4].endJunct=4;

	mapPtr->roads[5].start=getIntersectionByID(6, mapPtr);
	mapPtr->roads[5].startJunct=4;
	mapPtr->roads[5].end=getIntersectionByID(1, mapPtr);
	mapPtr->roads[5].endJunct=2;

	mapPtr->roads[6].start=getIntersectionByID(2, mapPtr);
	mapPtr->roads[6].startJunct=2;
	mapPtr->roads[6].end=getIntersectionByID(7, mapPtr);
	mapPtr->roads[6].endJunct=4;

	mapPtr->roads[7].start=getIntersectionByID(7, mapPtr);
	mapPtr->roads[7].startJunct=4;
	mapPtr->roads[7].end=getIntersectionByID(2, mapPtr);
	mapPtr->roads[7].endJunct=2;

	mapPtr->roads[8].start=getIntersectionByID(3, mapPtr);
	mapPtr->roads[8].startJunct=2;
	mapPtr->roads[8].end=getIntersectionByID(8, mapPtr);
	mapPtr->roads[8].endJunct=4;

	mapPtr->roads[9].start=getIntersectionByID(8, mapPtr);
	mapPtr->roads[9].startJunct=4;
	mapPtr->roads[9].end=getIntersectionByID(3, mapPtr);
	mapPtr->roads[9].endJunct=2;

	mapPtr->roads[10].start=getIntersectionByID(9, mapPtr);
	mapPtr->roads[10].startJunct=4;
	mapPtr->roads[10].end=getIntersectionByID(5, mapPtr);
	mapPtr->roads[10].endJunct=2;

	mapPtr->roads[11].start=getIntersectionByID(1, mapPtr);
	mapPtr->roads[11].startJunct=1;
	mapPtr->roads[11].end=getIntersectionByID(4, mapPtr);
	mapPtr->roads[11].endJunct=3;

	mapPtr->roads[12].start=getIntersectionByID(4, mapPtr);
	mapPtr->roads[12].startJunct=3;
	mapPtr->roads[12].end=getIntersectionByID(1, mapPtr);
	mapPtr->roads[12].endJunct=1;

	mapPtr->roads[13].start=getIntersectionByID(2, mapPtr);
	mapPtr->roads[13].startJunct=1;
	mapPtr->roads[13].end=getIntersectionByID(1, mapPtr);
	mapPtr->roads[13].endJunct=3;

	mapPtr->roads[14].start=getIntersectionByID(1, mapPtr);
	mapPtr->roads[14].startJunct=3;
	mapPtr->roads[14].end=getIntersectionByID(2, mapPtr);
	mapPtr->roads[14].endJunct=1;

	mapPtr->roads[15].start=getIntersectionByID(3, mapPtr);
	mapPtr->roads[15].startJunct=1;
	mapPtr->roads[15].end=getIntersectionByID(2, mapPtr);
	mapPtr->roads[15].endJunct=3;

	mapPtr->roads[16].start=getIntersectionByID(2, mapPtr);
	mapPtr->roads[16].startJunct=3;
	mapPtr->roads[16].end=getIntersectionByID(3, mapPtr);
	mapPtr->roads[16].endJunct=1;

	mapPtr->roads[17].start=getIntersectionByID(5, mapPtr);
	mapPtr->roads[17].startJunct=1;
	mapPtr->roads[17].end=getIntersectionByID(3, mapPtr);
	mapPtr->roads[17].endJunct=3;

	mapPtr->roads[18].start=getIntersectionByID(3, mapPtr);
	mapPtr->roads[18].startJunct=3;
	mapPtr->roads[18].end=getIntersectionByID(5, mapPtr);
	mapPtr->roads[18].endJunct=1;
	interConnect(mapPtr);
}
#endif
