#include "CarCmd.h"

#ifndef __SIMPLE_QUEUE__
#define __SIMPLE_QUEUE__

#ifndef MAXQUEUE
#define MAXQUEUE 5
#endif

// A simple queue implementation in array
struct queue
{
	uint8_t count;
	uint8_t front;
	uint8_t rear;
	CarCmdMsg entry[MAXQUEUE];
};

void copyEntry (CarCmdMsg *dest, CarCmdMsg *source)
{
	dest->c.speed = source->c.speed;
	dest->c.carID = source->c.carID;
	dest->c.length = source->c.length;
	
	dest->startTime.high32 = source->startTime.high32;
	dest->startTime.low32 = source->startTime.low32;
	dest->endTime.high32 = source->endTime.high32;
	dest->endTime.low32 = source->endTime.low32;
	
	dest->distance = source->distance;
	dest->reportBack = source->reportBack;
	dest->sourceID = source->sourceID;
	dest->msgType = source->msgType;
}

void clearEntry (CarCmdMsg *x)
{
	x->startTime.high32 = x->startTime.low32
		= x->endTime.high32 = x->endTime.low32=0;
	x->distance = x->sourceID = 0;
	x->c.speed = x->c.carID = x->c.length=0;
	x->reportBack = FALSE;
}
// Functions for the simple queue library
void append(CarCmdMsg *x, struct queue *q)
{
	if(q->count >= MAXQUEUE)
	{
		dbg(DBG_USR2, "Car: Too many cars in the queue.");
	}
	else
	{
		q->count++;
		q->rear=(q->rear+1)%MAXQUEUE;
		
		// Copy all of the attributes
		/*
		q->entry[q->rear].reportBack = x->reportBack;
		q->entry[q->rear].distance = x->distance;
		q->entry[q->rear].startTime = x->startTime;
		q->entry[q->rear].endTime = x->endTime;
		
		q->entry[q->rear].c.length = x->c.length;
		q->entry[q->rear].c.carID = x->c.carID;
		q->entry[q->rear].c.speed = x->c.speed;*/
		
		copyEntry (&(q->entry[q->rear]), x);
		// Car hasn't been initialized yet
		/*
		if (x->c.length==0)
			q->entry[q->rear].reportBack = 1;*/
		
	}
}

CarCmdMsg * findFirstPending (struct queue *q)
{
	uint8_t i=0;
	
	for (; i<q->count; i++)
	{
		if(q->entry[(q->front+i)%MAXQUEUE].c.length==0||q->entry[(q->front+i)%MAXQUEUE].c.speed==0)
			return &(q->entry[(q->front+i)%MAXQUEUE]);
	}
	return NULL;
}

void serve(CarCmdMsg *x, struct queue *q)
{
	if(q->count == 0)
	{
		dbg(DBG_USR2, "Car: Cannot serve from an empty queue.");
	}
	else
	{
		q->count--;
		
		if (x!=NULL)
			copyEntry(x, &(q->entry[q->front]));
		q->front=(q->front+1)%MAXQUEUE;
	}
}

uint8_t queueSize(struct queue *q)
{
	return q->count;
}

bool queueFull(struct queue *q)
{
	return q->count>=MAXQUEUE;
}

bool queueEmpty(struct queue *q)
{
	return q->count<=0;
}

CarCmdMsg * getFirst(struct queue *q)
{
	if(q->count == 0)
	{
		//dbg(DBG_USR2, "Car: Queue is empty.");
		return NULL;
	}
	else
	{
		return &(q->entry[q->front]);
	}
}

CarCmdMsg * getLast(struct queue *q)
{
	if(q->count == 0)
	{
		//dbg(DBG_USR2, "Car: Queue is empty.");
		return NULL;
	}
	else
	{
		return &(q->entry[q->rear]);
	}
}

#endif
