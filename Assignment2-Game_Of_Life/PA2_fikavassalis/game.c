/*
	Fivos Kavassalis -- fikavassalis
 */

#include "life.h"

/** dead function: For a cell that dies, assign 0 on next2D array cell
 *  @param k for row of array
 *  @param m for column of array
 *  @return 0
 */
int dead(int k,int m){
	next2D[k][m] = 0;
	return 0;
}

/** survived function: For a cell that survives, assign the value of the current2D array cell to the next2D array cell
 *  @param k for row of arrays
 *  @param m for column of arrays
 *  @return 0
 */
int survived(int k,int m){
	next2D[k][m] = current2D[k][m];
	return 0;
}

/** born function: For a cell that is born, assign 1 to the next2D array cell
 *  @param k for row of array
 *  @param m for column of array
 *  @return 0
 */
int born(int k,int m){
	next2D[k][m]= 1;
	return 0;
}

/** countNeighbors function: Counts the neighbors of a cell
 *  @param k for row of array
 *  @param m for column of array
 *  @return number of neighbors
 */
int countNeighbors(int k,int m){

	if(((k-1)< 0)&&((m-1)<0)){ //Top left
		return current2D[k+1][m]+current2D[k+1][m+1]+current2D[k][m+1];
	}else if(((k+2)> columns)&&((m-1)<0)){ //Top right
		return current2D[k-1][m]+current2D[k-1][m+1]+current2D[k][m+1];
	}else if((k-1)< 0&&(m+2)> rows){ //Bottom left
		return current2D[k+1][m]+current2D[k+1][m-1]+current2D[k][m-1];
	}else if((k+2)> columns && (m+2)>rows){ //Bottom right
		return current2D[k-1][m]+current2D[k-1][m-1]+current2D[k][m-1];
	}else if((m-1)<0){ //Top
		return current2D[k+1][m]+current2D[k+1][m+1]+current2D[k][m+1]+current2D[k-1][m]+current2D[k-1][m+1];
	}else if((m+2)>rows){ //Bottom
		return current2D[k-1][m]+current2D[k-1][m-1]+current2D[k][m-1]+current2D[k+1][m]+current2D[k+1][m-1];
	}else if((k-1)< 0){ //Left
		return current2D[k+1][m]+current2D[k+1][m+1]+current2D[k][m+1]+current2D[k][m-1]+current2D[k+1][m-1];
	}else if((k+2)>columns){ //Right
		return current2D[k-1][m]+current2D[k-1][m-1]+current2D[k][m-1]+current2D[k][m+1]+current2D[k-1][m+1];
	}else{//Elsewhwere
		return (current2D[k-1][m-1]+current2D[k-1][m]+current2D[k-1][m+1]+current2D[k][m-1]+current2D[k][m+1]+current2D[k+1][m-1]+current2D[k+1][m]+current2D[k+1][m+1]);
	}
}

/** forCell function: Decides death, survival or birth for a cell, according to the number of neighbors
 *  @param k for row of array
 *  @param m for column of array
 *  @return 1
 */
int forCell(int k,int m){

	int numOfNeighbors = countNeighbors(k,m);
	if((numOfNeighbors==0) ||(numOfNeighbors==1)||(numOfNeighbors==4)||(numOfNeighbors==5)||(numOfNeighbors==6)||(numOfNeighbors==7)||(numOfNeighbors==8)){
		dead(k,m);
	}else if((numOfNeighbors==2)||(numOfNeighbors==3)){
		survived(k,m);
	}
	if(numOfNeighbors==3){
		born(k,m);
	}
	return 1;
}
/** countNeighbors function: Does the forCell function (function above) for every cell (one generation)
 *  @return 1
 */
int PlayOne(){
	for (int i=0;i<columns; i++){
		for (int j=0;j<rows;j++){
			forCell(i,j);
		}
	}
	return 1;
}

/** manyGens function: Plays game for as many generations as instructed, or
 *  until one of the termination conditions is met.
 *  @return 0
 */
int manyGens(){

	for (int i=0;i<gens;i++){  // IT LOOPS FOR HOW EVER MANY GENERATIONS ARE GIVEN

		copy2D(current2D,past2D);
		PlayOne();
		copy2D(next2D,current2D);

		if(doPrint){
			printf("Generation number %d\n",i+1 );
			printArray(current2D,columns,rows);
		}

		if(doPause){
			getchar();
		}

		if (equals(past2D,current2D)){//CHECKS IF THE CURRENT ARRAY IS  THE SAME AS THE PAST ARRAY
			printf("The Game has been terminated in the generation number %d, since it repeats itself. \n", i+1);
			break;
		}else if(equals(empty2D,current2D)){//CHECKS IF THE CURRENT ARRAY IS  THE SAME AS AN EMPTY ARRAY
			printf("The Game has been terminated in the generation number %d, since there are no organisms alive. \n", i+1);
			break;
		}else if (i == gens-1){
			printf("The Game has been terminated under normal conditions, since it reached the generation number %d. \n",i+1 );
		}
	}
	printf("\n");
	printf("\n");
	printArray(current2D,columns,rows);  // PRINTS THE 2D ARRAY
	return 0;
}
