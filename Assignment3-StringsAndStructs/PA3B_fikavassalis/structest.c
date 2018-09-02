#include <stdio.h>
#include "mystruct.h"
#include <stdlib.h>

int main(int atgc, char *argv[]) {
	struct Employee *e, *p, *ptoE, *ranP;
	struct Employee **ranPM1, **ranPM2, **rPM1d, **rPM2d, **pd21, **pd22;

	// Testing makeEmployee() and printEmployee()
	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	p = makeEmployee(1998, 2016, "Fivos Kavassalis");
	ptoE = makeEmployee(3000, 3050, "James Smith");

	printEmployee(e);
	printEmployee(p);
	printEmployee(ptoE);

	printf("\n\n");

	// For all random employees, every new time program runs,
	// fields get different values
	ranP = makeRandomEmployee(); // Testing makeRandomEmployee() and printEmployee()
	printEmployee(ranP);

	printf("\n\n");

	ranPM1 = makeRandomEmployees(5); // Testing makeRandomEmployees() and printEmployees()
	printEmployees(ranPM1, 5);

	printf("\n\n");

	ranPM2 = makeRandomEmployees(5);
	printEmployees(ranPM2, 5);

	printf("\n\n");

	rPM1d = duplicatePEmployees(ranPM1, 5); // Testing mduplicateEmployees() and printEmployees()
	printEmployees(rPM1d, 5);

	printf("\n\n");

	rPM2d = duplicatePEmployees(ranPM2, 3); // To test when not all pointers are duplicated (3 of 5 in this case)
	printEmployees(rPM2d, 3);

	printf("\n\n");

	pd21 = duplicatePEmployeesTwo(ranPM1, 5); // Testing duplicatePEmployeesTwo() and printEmployees()
	printEmployees(pd21, 5);

	printf("\n\n");

	pd22 = duplicatePEmployeesTwo(ranPM1, 3);
	printEmployees(pd22, 3);

	printf("\n\n");

	int a = freeStructs(ranPM1, 5);    // Testing freeStructs()
	printf("Check if freeStructs is working properly: %d\n", a);
	int b = freeStructs(ranPM2, 5);
	printf("Check if freeStructs is working properly: %d\n", b);
	int c = freeStructs(rPM1d, 5);
	printf("Check if freeStructs is working properly: %d\n", c);
	int d = freeStructs(rPM2d, 3);
	printf("Check if freeStructs is working properly: %d\n", d);
	int f = freeStructs(pd21, 3);
	printf("Check if freeStructs is working properly: %d\n", f);
	int j = freeStructs(pd22, 3);
	printf("Check if freeStructs is working properly: %d\n", j);

	free(e);
	free(p);
	free(ptoE);
	free(ranP);

	return 0;
}
