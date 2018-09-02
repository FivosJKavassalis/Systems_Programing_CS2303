/*
 * Events.h
 *
 *  Created on: Feb 16, 2018
 *  @author: mbpatel
 *  @author: fikavassalis
 */

#ifndef EVENTS_H_
#define EVENTS_H_

#include "qSim.h"

class Events{
public:
	Events();	//constructor
	~Events();	//destructor
	class Event;	//class of the linked list's nodes
	float CurrentTime;
	void Insert(float sT, float tS, int T);
	Event *First;	//First of the list
	Event *current; //Directionrary nodes used for
	Event *Direction;	//traversal of the list
	class Event{
	public:
		float startTime, timeServed;	//starting time of the event and time reuired for it to be served
		Event* next; //node pointing to the next event of the queue
		int type;	 //distinguish between types of events
	};

};

#endif /* EVENTS_H_ */
