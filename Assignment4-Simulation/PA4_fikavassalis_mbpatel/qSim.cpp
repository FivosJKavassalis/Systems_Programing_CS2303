/*
 * qSim.cpp
 *
 *  Created on: Feb 16, 2018
 *  @author: mbpatel
 *  @author: fikavassalis
 */


#include "qSim.h"
#include "Events.h"
#include "Customers.h"


int main(int argc, char *argv[]) {

	//Random arrival Time of a Customer
	float  randArrivalTime;

	//Random time Required for customer to be served
	float  randomTime;

	//Time Teller Spent Idol
	float  timeWaiting;

	//Customers served during the simulation time
	int servedNumCustomers = 0;

	//time customers were held in line
	float timeOnHold = 0.0;

	//maximum time the customers were held in line
	float maximumTime = 0.0;

	//total time the tellers were in service
	float totalServiceTime = 0.0;

	//total time the tellers were idol
	float totalIdleTime = 0.0;

	//free tellers :type-1 event
	const int freeTeller = 1;

	//event type with customer arriving :type-2 event
	const int customerArrival = 2;

	//event were the customer being serviced :type-3 event
	const int customerComplete = 3;

	//the seed of rand
	srand(time(NULL));

	//Events Line for the COMMON LINE SIMULATION
	Events E;

	//Customer Line for the COMMON LINE SIMULATION
	Customers C;


	//****************************************************************************


	//initializing all the variables from the commend line:

	const int CustomersNum = atoi(argv[1]);

	const int Tellers   = atoi(argv[2]);

	const float SimulationTime = atof(argv[3]);

	const float AverageTime    = atof(argv[4]);

	//check to see if there a seed argument given
	if (argc == 6)
	{
		srand(atoi(argv[5]));
	}



	//****************************************************************************



	//Run the common line simulation first:

	//create all the customers
	for (int i = 0; i < CustomersNum; i++)
	{
		//initialize the Customers in the Common Customer Line
		randArrivalTime = SimulationTime * rand()/float(RAND_MAX);

		randomTime = 2 * AverageTime * rand()/float(RAND_MAX);

		//create the customer
		C.Insert(randArrivalTime, randomTime);
	}


	//Crate the tellers
	for (int i = 0; i< Tellers; i++)
	{
		//initialize the tellers as free at time=0
		E.Insert(E.CurrentTime, 0, freeTeller);
	}


	//get the first node of the customer linked list queue
	C.Direction = C.First;


	//crate the customer linked list queue
	while(C.Direction != NULL)
	{
		//adding the customer arrival events, to the event queue
		E.Insert(C.Direction->arrivalTime, C.Direction->timeReq, customerArrival);

		//get the next node of the customer linked list
		C.Direction = C.Direction->Next;
	}

	//------------------------------------------------------

	//get the first node of the event linked list queue
	E.current = E.First;

	//is teller free event type holder
	bool check;

	//Process the events queue and gather data
	while(	(servedNumCustomers < CustomersNum)	&&	((E.CurrentTime) < SimulationTime))
	{
		//inveritant = Customers processed/served is less then the number of customers given and event being processed has its time less then simulation time

		//get the first node
		E.Direction = E.First;

		check = false;

		//ACTION OF A TELLER
		if(E.current->type==freeTeller )
		{
			//check to find a teller free event type-1
			while((E.Direction) && (check==false))
			{
				if((E.Direction->type==customerArrival)&&(E.Direction->startTime<E.current->startTime))
				{
					//check to find a customer already in the common line type-2
					E.Insert((E.current->startTime+E.Direction->timeServed), 0, customerComplete);

					E.Insert((E.current->startTime+E.Direction->timeServed), 0, freeTeller );

					//make the customer event to a customer complete event
					E.Direction->type=customerComplete;

					//check that the teller actually worked (so no reason to idle him)
					check=true;

					//increment the numbers of customers served
					servedNumCustomers++;

					//increase the time waiting of a customer by the difference of the time he got served and the time he arrived at the bank
					timeOnHold = timeOnHold + (E.current->startTime - E.Direction->startTime) + E.Direction->timeServed;

					//if the waiting time is bigger than the max waiting time set the new to max to the current difference
					if((E.current->startTime - E.Direction->startTime) > maximumTime)
					{
						maximumTime=(E.current->startTime-E.Direction->startTime);
					}

					//increase the total amount of service
					totalServiceTime=totalServiceTime+E.Direction->timeServed;
				}

				//go to the next event
				E.Direction=E.Direction->next;
			}

			//if no customer found, set teller to idle
			if(check==false)
			{
				timeWaiting = 1.5*rand()/float(RAND_MAX);

				//Set the teller to idol
				E.Insert((E.current->startTime+timeWaiting), 0, freeTeller );

				//add idol time to the total idol time
				totalIdleTime = totalIdleTime + timeWaiting;
			}

			//the tellerFree is no longer at this event so make the type NULL
			E.current->type=0;
		}

		//get the next event
		E.current= E.current->next;

		//get the next event time
		E.CurrentTime=E.current->startTime;
	}

	//------------------------------------------------------

	//get the average waiting time
	timeOnHold=timeOnHold/servedNumCustomers;

	//Print the data gathered for common line queue
	cout << "**********  This is the output for a common queue  **********   \n" << endl;
	cout << "  Number of customers served within the simulation time is: " << servedNumCustomers << endl;
	cout << "  Total service time to serve all customers is: " << E.CurrentTime << endl;
	cout << "  Number of tellers: " << Tellers << endl;
	cout << "  The average time a customer spent in the bank is: " << timeOnHold << endl;
	cout << "  Max waiting time of a customer is: " << maximumTime  << endl;
	cout << "  Total amount of teller service time: " << totalServiceTime << endl;
	cout << "  Total amount of time the tellers were idle: " << totalIdleTime  << endl;

	//END OF SIMULATION ONE, COMMON LINE



	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



	//START SIMULATION FOR SEPERATE TELLER LINES:


	//re-initialize all statistic variables:
	servedNumCustomers = 0;
	timeOnHold = 0;
	maximumTime	= 0;
	totalServiceTime = 0;
	totalIdleTime = 0;


	//****************************************************************************


	//create an array of customer lists for the separate teller lines
	Customers tellerLines[Tellers];

	//Event Queue for the separate teller lines simulation
	Events D;


	//****************************************************************************


	//Initialize customer line for each teller with customer
	for (int i = 0; i < CustomersNum; i++)
	{
		//Create a random arrival time
		randArrivalTime = SimulationTime*rand()/float(RAND_MAX);

		randomTime = 2*AverageTime*rand()/float(RAND_MAX);

		//add the customer to a teller line
		tellerLines[(i%(Tellers))].Insert(randArrivalTime, randomTime);
	}


	//add tellers to the event queue
	for (int i = 0; i< Tellers; i++)
	{
		//initialize the tellers as free at time=0
		D.Insert(D.CurrentTime, 0, i);
	}

	//------------------------------------------------------

	//add in the event queue all the customer lines
	for(int i = 0; i < Tellers; i++)
	{
		//Invariant = less then the number of teller lines (number of tellers)

		//get the first node in the given teller line
		tellerLines[i].Direction = tellerLines[i].First;

		//
		while(tellerLines[i].Direction)
		{
			//Invariant = true as long as there a node present for a given teller line

			//insert the given node into the event queue
			D.Insert(tellerLines[i].Direction->arrivalTime, tellerLines[i].Direction->timeReq, i+Tellers);

			//get the next given teller line node
			tellerLines[i].Direction = tellerLines[i].Direction->Next;
		}
	}

	//------------------------------------------------------

	//get the first event from the events queue
	D.current = D.First;

	//process the events event queue
	while((servedNumCustomers<CustomersNum)	&&	((D.CurrentTime) < SimulationTime))
	{
		D.Direction = D.First;

		check=false;

		if(D.current->type < Tellers)
		{
			//scan the event queue for the first teller
			while((D.Direction) && (check == false))
			{
				//ACTION OF A TELLER
				//check if he has any customer in his line
				if((D.Direction->type == ((D.current->type) + Tellers)) && (D.Direction->startTime < D.current->startTime))
				{
					//if yes, serve him
					D.Insert((D.current->startTime + D.Direction->timeServed), 0, 2 * Tellers + 1);

					D.Insert((D.current->startTime + D.Direction->timeServed), 0, D.current->type);

					D.Direction->type = 2 * Tellers + 1;

					D.current->type = 2 * Tellers + 1;

					check=true;

					//increment the customers served variable
					servedNumCustomers++;


					timeOnHold=timeOnHold+(D.current->startTime-D.Direction->startTime)+D.Direction->timeServed;

					if((D.current->startTime-D.Direction->startTime)>maximumTime)
					{
						maximumTime=(D.current->startTime-D.Direction->startTime);
					}

					//add to the total amount of service time
					totalServiceTime=totalServiceTime+D.Direction->timeServed;
				}

				D.Direction=D.Direction->next;
			}


			//if not, check the other lines
			D.Direction = D.First;

			while((D.Direction)&&(check==false))
			{
				if(((D.Direction->type)>Tellers)&&((D.Direction->type)<2*Tellers+1)&&(D.Direction->startTime<D.current->startTime))
				{
					//if yes, serve him
					D.Insert((D.current->startTime+D.Direction->timeServed), 0, 2*Tellers+1);

					D.Insert((D.current->startTime+D.Direction->timeServed), 0, D.current->type);

					D.Direction->type=2*Tellers+1;

					D.current->type=2*Tellers+1;

					check=true;

					//increment the number of customers served
					servedNumCustomers++;

					//add to the waiting time the difference between the arrival
					timeOnHold = timeOnHold + (D.current->startTime-D.Direction->startTime) + D.Direction->timeServed;

					//time of the customer and when he got served
					if((D.current->startTime-D.Direction->startTime) > maximumTime)
					{
						//if the difference is the biggest observed make the max waiting time to the current one
						maximumTime=(D.current->startTime-D.Direction->startTime);}

					//add to the total service time
					totalServiceTime=totalServiceTime+D.Direction->timeServed;
				}

				D.Direction=D.Direction->next;
			}

			if(check==false)
			{
				//if no customers found idle him
				timeWaiting= 1.5*rand()/float(RAND_MAX);

				D.Insert((D.current->startTime+timeWaiting), 0, D.current->type);

				totalIdleTime=totalIdleTime+timeWaiting;
			}

			//the teller of this event already did his job and got moved to another event in the queue, so the type of this node is set to something big
			D.current->type=2 * Tellers + 1;
		}

		D.current=D.current->next;

		D.CurrentTime=D.current->startTime;
	}


	//------------------------------------------------------

	//get the average waiting time
	timeOnHold=timeOnHold/servedNumCustomers;

	cout << endl << endl << "**********  This is the output for queues one per teller   **********     \n" << endl;
	cout << "  Number of customers served within the simulation time is: " << servedNumCustomers << endl;
	cout << "  Total service time to serve all customers is: " << D.CurrentTime << endl;
	cout << "  Number of tellers: " << Tellers << endl;
	cout << "  Average time a customer spent in the bank is: " << timeOnHold << endl;
	cout << "  Max waiting time of a customer is: " << maximumTime<<  endl;
	cout << "  Total amount of teller service time: " << totalServiceTime << endl;
	cout << "  Total amount of time the tellers were idle: " << totalIdleTime<< endl;

	return 0;
}


