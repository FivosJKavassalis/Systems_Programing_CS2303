/** mystruct.c
 * @author Mike Ciaraldi
 * @author Fivos Kavassalis
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystruct.h"
#include <time.h>

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee* eP = (struct Employee*) malloc(sizeof(struct Employee));
	eP->birth_year = birth;
	eP->start_year = start;
	strcpy(eP->name, name);
	return eP;
}

/** Prints an Employee
 * @param e Pointer to Employee struct
 * @return void
 */
void printEmployee(struct Employee *e) {
	printf("Name of Employee: %s, birth year: %d, start year: %d\n", e->name,
			e->birth_year, e->start_year);
}

/** Make an Employee with random data
 * @return Pointer to Employee struct
 */
struct Employee* makeRandomEmployee() {
	int i;

	srand(time(0));
	char name[MAX_NAME + 1];
	int birthY = getRandomInt(1950, 1970); // inserted years so they make some
	int startY = getRandomInt(1988, 2018); //  kind of correlation
	int nameSize = getRandomInt(3, MAX_NAME);
	for (i = 0; i < nameSize; i++) {
		name[i] = (char) getRandomInt('a', 'z'); // do it namesize times
	}
	name[i] = '\0';

	return makeEmployee(birthY, startY, name);

}

/** Generates a random integer from a selected range
 * @param from Smallest number of range of the return value
 * @param to Biggest number of range of the return value
 * @return Random integer from requested range
 */
int getRandomInt(int from, int to) {
	int rangeD = to - from + 1; // add one to include limit values of range wen
	return (from + (rand()%rangeD));
}

/** fills in an array of pointers where each pointer points to
 * an Employee struct filled with random data
 * @param count Number of pointers to be in the array
 * @return Filled array of pointers
 */
struct Employee** makeRandomEmployees(int count) {
	struct Employee **ar = NULL;

	ar = (struct Employee**) malloc(sizeof(struct Employee*) * count);
	for (int i = 0; i < count; i++) {
		ar[i] = makeRandomEmployee(); // do it count times
	}

	return ar;

}

/** Prints out all the Employees of the pointers in the array
 * @param Array of pointers
 * @param count Number of pointers to be in the array
 * @return void
 */
void printEmployees(struct Employee **ar, int count) {

	for(int i=0; i<count; i++) {
		printEmployee(ar[i]); // do count times
	}

}

/** Duplicates an array of pointers to structs of this type ("shallow copy") -- Part 5
 * @param ar Array of pointers
 * @param numOfEl Number of pointers in the array
 * @return Duplicated array of pointers
 */
struct Employee** duplicatePEmployees(struct Employee **ar, int numOfEl) {
	struct Employee **dupAr = NULL;

	dupAr = (struct Employee**) malloc(sizeof(struct Employee*) * numOfEl);

	for(int i=0; i<numOfEl; i++) {
		dupAr[i] = ar[i]; // do numOfEl times
	}

	return dupAr;
}

/** Takes an array of pointers to the struct, and frees
 *  all the structs pointed to
 * @param ar Array of pointers
 * @param numOfEl Number of pointers in the array
 * @return 1, to check that it is running
 */

int freeStructs(struct Employee **ar, int numOfEl) {

	for(int i=0; i<numOfEl; i++) {

			free(ar[i]);    // do it numOfEl times
	}

	free(ar);

	return 1; // check that function runs properly
}

/** Duplicates an array of pointers to structs of this type ("deep copy") -- Part 7
 * @param ar Array of pointers
 * @param numOfEl Number of pointers in the array
 * @return Duplicated array of pointers
 */
struct Employee** duplicatePEmployeesTwo(struct Employee **ar, int numOfEl) {
	struct Employee **dupAr = NULL;

	dupAr = (struct Employee**) malloc(sizeof(struct Employee*) * numOfEl);

	for(int i=0; i<numOfEl; i++) {
		dupAr[i] = makeEmployee(ar[i]->birth_year, ar[i]->start_year, ar[i]->name);  // do it numOfEl times
	}

	return dupAr;
}

