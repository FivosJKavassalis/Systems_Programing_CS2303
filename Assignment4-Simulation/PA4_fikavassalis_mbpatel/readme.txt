Assignment #4
Milap Patel, mbpatel
Fivos Kavassalis, fikavassalis


Program Summary:
	This program simulates a given number of customers and tellers in a bank and compares the average time a customer spends in the bank, max wait time for a customer, number of customers served within the simulation time, the total teller service time, and the total teller idle time between a common teller service line vs. multi teller service lines. The compression will be seen in the command console after the program has run.



Solution:
	It is determined that the common queue is faster and more efficient vs. the multiple queues for a bank. 



INSTRUCTIONS BELOW:

Instructions on how to open, compile, link, run and clean from the command line:
    After going to the specific directory,
1) unzip by:  unzip PA4_mbpatel_fikavassalis
2) change directory again: cd PA4_mbpatel_fikavassalis
3)   make all
4)   run with  “./qSim #customers #tellers simulationTime averageServiceTime <seed>”, where seed is optional 
5)   make clean


Instructions on how to open, compile, link, run and clean from Eclipse:
1) Import zip by clicking File→Import
2) General→Existing Projects into Workspace
3) Then, click on Archive file and search for PA4_mbpatel_fikavassalis.zip
4) Right-click on project, and select “Build Project”
5) Right-click again, but select "Run As" and then “Run Configurations...”
6) Set up input and executable, and hit Run
7) Click “Clean Project” by right-clicking on project




The program is structured in the following way:
	
	The customers are objects that are added to the event queue via pointers.
	Tellers are also objects which are then added to the event queue via pointers.
	When the events are run one of the two about objects will be seen, which will invoke appropriate actions according to the object. 
  


Problems:
	We had a hard time understanding how the queue system worked and so we had a friend help us understand how to approach writing the program and made sure we were using the correct syntax for C++. 
