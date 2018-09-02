README – PA3B
Fivos Kavassalis/fikavassalis





The main() function in section B, also works as a test for the functionality and sanity of the functions created in mystruct.c . Those functions revolve around the Employee struct (Struct consists of two ints, the birth year and the start year and a character array that holds the name). The first function we were assigned to make was makeEmployee which allocates a struct and fills in its fields, returning a pointer to that struct. The program has also the printEmployee function that takes in a pointer to an Employee, and prints out this Employee’s fields. The makeRandomEmployee() function generates an employee filled with random data. I tried to pick ranges for birth year and start year that make sense with each other (last birth year is 18 years smaller than start year). Also the name is in the range of the all-small letter alphabet. I am using the helper function getRandomInt() to get an integer randomly from a range. It is used for all three fields. For the name I’m using a loop to generate a random name based on the random integer generated. Then, makeRandomEmployees() just generates an array of pointers to Employee structs that are filled in with random data. The next function is printEmployees(), which prints the Employees tha the pointers from the array, point to. Functions duplicatePEmployees() (“shallow method”) and duplicatePEmployeesTwo (“deep copy”), are duplicating an array of pointers to Employees structs. However, for the former we duplicate the pointers , whereas for the latter, we duplicate the structs! Finally, freeStructs(), frees all the structs pointed by the pointers from the array of pointers.





INSTRUCTIONS BELOW:
Instructions on how to open, compile, link, run and clean from the command line:
	After going to the specific directory,
1) unzip by:  unzip PA3B_fikavassalis;
2) change directory again: cd PA3B_fikavassalis
3)   make all
4)   run with  “./structest” 
5)   make clean


Instructions on how to open, compile, link, run and clean from Eclipse:
1) Import zip by clicking File→Import
2) General→Existing Projects into Workspace
3) Then, click on Archive file and search for PA3B_fikavassalis.zip
4) Right-click on project, and select “Build Project”
5) Right-click again, but select “Run as→Local C/C++ Application ”
6) Click “Clean Project” by right-clicking on project

