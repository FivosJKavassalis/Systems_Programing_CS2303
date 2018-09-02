/** mystruct.h
 * @author Mike Ciaraldi
 * @author Fivos Kavassalis
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employee started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
struct Employee* makeRandomEmployee();
int getRandomInt(int from, int to);
struct Employee** makeRandomEmployees(int count);
void printEmployees(struct Employee **ar, int count);
struct Employee** duplicatePEmployees(struct Employee **ar, int numOfEl);
int freeStructs(struct Employee **ar, int numOfEl);
struct Employee** duplicatePEmployeesTwo(struct Employee **ar, int numOfEl);



