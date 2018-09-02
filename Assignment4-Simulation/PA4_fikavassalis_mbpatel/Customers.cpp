/**
 * Customers.cpp
 *
 *  Created on: Feb 16, 2018
 *  @author: mbpatel
 *  @author: fikavassalis
 */



#include "Customers.h"



//==============================================================



/**
 *  Initializes the customers linked list -- Constructor
 */
Customers::Customers() {

	//initializing the Linked List
	First=NULL;
	Direction=NULL;
}



//==============================================================



/**
 *  Deletes the customers linked list -- Destructor
 */
Customers::~Customers() {

	//get the first element of the list given
	Customer *Direction = First;

	//deleting the Linked List
	while (Direction!=NULL)
	{
		//Invariant = true if there is a node

		//get the next node
		Customer *q = Direction -> Next;

		delete Direction;

		Direction = q;
	}
}



//==============================================================



/** Inserts new customer to list of customers
 * @param aFloat arrival time of new customer
 * @param bFloat time required for new customer to be served
 * @return void
 */
void Customers::Insert(float arrivalTime, float serviceTime){

	//insert a new Node to the list;
	Customer *Direction = new Customer();

	Direction->arrivalTime = arrivalTime;

	Direction->timeReq = serviceTime;

	if (!First)
	{
		//if there's no First, initialize it
		First = Direction;

	}

	else if (Direction->arrivalTime < First->arrivalTime)
	{
		//if the node to be inserted has to be before the current First
		Direction -> Next = First;

		First = Direction;

	}

	else
	{
		//else check where the node is supposed to be inserted
		Customer *q = First;

		while ((q -> Next) && (q -> Next -> arrivalTime < Direction -> arrivalTime))
		{
			q = q -> Next;
		}

		Direction -> Next = q -> Next;

		q -> Next = Direction;
	}
}



