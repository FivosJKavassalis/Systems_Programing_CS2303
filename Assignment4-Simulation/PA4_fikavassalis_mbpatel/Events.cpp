/*
 * Events.cpp
 *
 *  Created on: Feb 16, 2018
 *  @author: mbpatel
 *  @author: fikavassalis
 */




#include "Events.h"


/**
 *  Initializes the events linked list -- Constructor
 */
Events::Events() {
	//initializing the Linked List
	CurrentTime=0;
	First=NULL;
	current=NULL;
	Direction=NULL;

}



/**
 *  Deletes the events linked list -- Destructor
 */
Events::~Events() {
	//deleting the Linked List
	Event *temp = First;
	Event *q;
	while (temp!=NULL) {
		q = temp -> next;
		delete temp;
		temp = q;
	}

}



/** Inserts new event to list of events
 * @param sT starting time of new event
 * @param tS time required for new event to be served
 * @param T type of event
 * @return void
 */
void Events::Insert(float sT, float tS, int T){

	//inserting an Event to the Linked List
	Event *temp = new Event();
	temp-> startTime = sT;
	temp->timeServed = tS;
	temp-> type 	 = T;
	if (!First) {
		//if there is no First, initialize it
		First = temp;
		return;
	}

	else if (temp->startTime<First->startTime) {
		//if the event takes place before the First's event
		temp -> next = First;
		First = temp;
	}

	else {
		//else search for the proper position to insert the event
		Event *q = First;
		while ((q -> next) && (q -> next -> startTime < temp -> startTime)){
			q = q -> next;
		}

		temp -> next = q -> next;
		q -> next = temp;
	}
}


