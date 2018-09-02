/*
	Fivos Kavassalis -- fikavassalis
 */

#include "life.h"

/** equals function: Checks if the two 2D arrays given are the same
 *  @param Array1 for the 1st 2D array
 *  @param Array2 for the 2nd 2D array
 *  @return 1 if true or zero if false
 */
int equals (int **Array1,int **Array2){
	int equal = 1;
	for (int i=0;i<columns; i++){ // LOOPS THROUGH ALL THE ROWS
		for (int j=0;j<rows;j++){ // LOOPS THROUGH ALL THE COLUMNS
			equal = (equal && (Array1[i][j] == Array2[i][j]));  // MAKES THE EQUAL VARIABLE EQUAL TO TRUE OR FALSE DEOENDING IF THE TWO ELEMENTS OF THE ARRAYS ARE EQUAL
		}
	}
	return equal;
}
/** copy2D function: Copies the values of a 2D array to another 2D array
 *  @param Array1 for the 1st 2D array
 *  @param Array2 for the 2nd 2D array
 *  @return 1
 */
int copy2D(int **Array1,int **Array2){
	for (int i=0;i<columns; i++){  // LOOPS THROUGH ALL THE ROWS
		for (int j=0;j<rows;j++){  // LOOPS THROUGH ALL THE COLUMNS
			Array2[i][j] = Array1[i][j];  // MAKES AN ELEMENT TO EQUAL TO ANOTHER ELEMENT
		}
	}
	return 1;
}
/** fillZero function: Sets all the values of a 2D array to 0
 *  @param Array1 for the 1st 2D array
 *  @return 1
 */
int fillZero(int **Array1){
	for (int i=0;i<columns; i++){  // LOOPS THROUGH ALL THE ROWS
		for (int j=0;j<rows;j++){ // LOOPS THROUGH ALL THE COLUMNS
			Array1[i][j] = 0;  // MAKES AN ELEMENT TO EQUAL TO 0
		}
	}
	return 1;
}

/** printArray function: Print a 2D array
 *  @param Array1 for the 1st 2D array
 *  @param columns for the columns of the array
 *  @param rows for the rows of the array
 *  @return 1
 */
int printArray(int **Array1,int columns, int rows){
	for (int i=0;i<columns; i++){  // LOOPS THROUGH ALL THE ROWS
		for (int j=0;j<rows;j++){ // LOOPS THROUGH ALL THE COLUMNS
			if (Array1[i][j] == 0)  {
				printf("o");
			}else{
				printf("x");
			}
		}
		printf("\n");
	}
	return 1;
}
