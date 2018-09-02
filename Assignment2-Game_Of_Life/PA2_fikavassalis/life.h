/*
	Fivos Kavassalis -- fikavassalis
*/

// Libraries
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Global variables:
#define BUFFSIZE 1024

int columns,rows,gens; // Definition for columns, rows, and generations
int **past2D; // PAST LIFE
int **current2D; // CURRENT LIFE
int **next2D; // NEXT LIFE
int **empty2D; // EMPTY 2D ARRAY
int **extra2D; // EXTRA 2D ARRAY
int doPrint;
int doPause;
int columnsAct;
int rowsAct;
char read[BUFFSIZE];
char *token;

// Function Prototypes:
int dead(int k, int m);
int survived(int k, int m);
int born(int k, int m);
int countNeighbors(int k, int m);
int forCell(int k, int m);
int PlayOne();
int manyGens();
int equals (int **Array1,int **Array2);
int copy2D(int **Array1,int **Array2);
int fillZero(int **Array1);
int printArray(int **Array1, int columns, int rows);
