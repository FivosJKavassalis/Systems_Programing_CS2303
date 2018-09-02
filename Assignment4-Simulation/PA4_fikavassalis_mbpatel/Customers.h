/**
 * Customers.h
 *
 *  Created on: Feb 16, 2018
 *  @author: mbpatel
 *  @author: fikavassalis
 */

#ifndef CUSTOMERS_H_
#define CUSTOMERS_H_

#include "qSim.h"

class Customers{
public:

	class Customer;

	//Directionrary pointer used for traversal
	Customer *Direction;

	//First of the linked list
	Customer *First;

	//insert function
	void Insert(float arrivalTime, float serviceTime);

	//constructor
	Customers();

	//destructor
	~Customers();


	class Customer{
	public:

		//node pointing to the next node of the list
		Customer *Next=NULL;

		//time when the customer arrives
		float arrivalTime;

		//time required for a customer to be served
		float timeReq;
	};

};




#endif /* CUSTOMERS_H_ */
