/*
	Fivos Kavassalis -- fikavassalis
*/

#include "life.h"


/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 * @return EXIT_SUCCESS if success, or EXIT_FAILURE if invalid command line or unable to open file.
 */
int main(int argc, char *argv[]){

  printf("Game of Life\n");
  printf("\n");
  printf("\n");
	// Read required inputs
  columns = atoi(argv[1]);
	rows = atoi(argv[2]);
	gens = atoi(argv[3]);
	FILE *file = fopen(argv[4],"r");


	// See if there is the right number of arguments set in the command line
	if ((argc < 5) || (argc > 7)) {
		// If not, tell the user what to enter.
		printf("Usage:\n");
		printf("  ./life rows columns generations inputFile [print] [pause]\n");
		return EXIT_FAILURE;
	}

  // Check if rows and columns inputs are valid for this game (positive numbers)
  if(rows <= 0 || columns <= 0){
		printf("Rows and columns must have a positive number.\n");
		return EXIT_FAILURE;
	}

  // Following 3 blocks set up print and pause inputs
  if (argc == 5) {
		doPrint = 0;
		doPause = 0;
	}

	if (argc == 6) {
    if (argv[5][0] == 'y') {
			 doPrint = 1;
			 doPause = 0;
		} else if (argv[5][0] == 'n') {
			 doPrint = 0;
			 doPause = 0;
		} else {
 		   printf("Wrong character for print! Insert 'y' or 'n'.\n");
		   return EXIT_FAILURE;
		}
	}

	if (argc == 7) {
    if (argv[5][0] == 'y' && argv[6][0] == 'y') {
			 doPrint = 1;
			 doPause = 1;
		} else if (argv[5][0] == 'y' && argv[6][0] == 'n') {
			 doPrint = 1;
			 doPause = 0;
		} else if (argv[5][0] == 'n' && argv[6][0] == 'y') {
			 doPrint = 0;
			 doPause = 1;
		} else if (argv[5][0] == 'n' && argv[6][0] == 'n') {
			 doPrint = 0;
			 doPause = 0;
		} else {
 		   printf("Wrong characters for print and/or pause! Insert 'y' or 'n' for print and pause arguments.\n");
		   return EXIT_FAILURE;
		}
	}

	// Allocate memory for all the 2D arrays
	past2D = malloc(columns*sizeof(int*)); // For the past 2D array
	for(int i=0;i<columns;i++){
		*(past2D+i) = malloc(rows*sizeof(int));
	}
	current2D = malloc(columns*sizeof(int*));  // For the current 2D array
	for(int i=0;i<columns;i++){
		*(current2D+i) = malloc(rows*sizeof(int));
	}
	next2D = malloc(columns*sizeof(int*));   // For the nextt generation's 2D array
	for(int i=0;i<columns;i++){
		*(next2D+i) = malloc(rows*sizeof(int));
	}
	empty2D = malloc(columns*sizeof(int*));   // For the empty 2D array
	for(int i=0;i<columns;i++){
		*(empty2D+i) = malloc(rows*sizeof(int));
	}

	// Fill all the 2D arrays with 0 for every tile using helper function fillZero
	fillZero(past2D);
	fillZero(current2D);
	fillZero(next2D);
	fillZero(empty2D);

	// Read the text file, count length of line for columns of each row to create extra2D with exactly the same rows and columns as in the input file (based on 'x' and 'o')
	if (file){
    columnsAct=0;
    rowsAct=0;
    while (fgets(read, sizeof(read), file) != NULL){
      token = strtok(read, "\n");
      columnsAct=(unsigned)strlen(token);
      rowsAct++;
    }
		fclose(file); // close file
	}
  // Allocate memory for extra2D (# of allocated rows and columns based on input file)
  extra2D = malloc(columnsAct*sizeof(int*));
	for(int i=0;i<columnsAct;i++){
		*(extra2D+i) = malloc(rowsAct*sizeof(int));
	}

  // Open file again, store 'x' as 1 and 'o' as 0
  file = fopen(argv[4],"r");
  char c;
  if (file){
		for(int i =0; i<columnsAct;i++){
      fgets(read, sizeof(read), file);
      token = strtok(read, "\n");
      for(int j=0; j<rowsAct;j++){
        c = token[j];
        if (c=='o'){
          extra2D[i][j]=0;
        }
        else if(c=='x'){
          extra2D[i][j]=1;
        }
        else{
          printf("Wrong input for the text file, check that it includes only 'x' or 'o' notations!\n");
          return EXIT_FAILURE;
        }
      }
    }
		fclose(file);
	}

  int x = ceil((columns-columnsAct)/2); // ROUND-UP
  int y = ceil((rows-rowsAct)/2); // ROUND-UP

  for(int i=0; i<columnsAct; i++){
    for(int j=0; j<rowsAct; j++){
      current2D[x+i][y+j] = extra2D[i][j];
    }
  }

  if(columnsAct>columns || rowsAct>rows ){
    printf("Wrong input for columns and rows!\n");
    return EXIT_FAILURE;
  }

	// Play the game
	manyGens();

	return EXIT_SUCCESS;
}
