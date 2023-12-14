/* name : laby.c
 * author : matheo thomas
 * date : 14-12-23
 */

#include <stdio.h>
#include <stdlib.h>

#include "laby.h"


int **initLaby(){
	int **laby = (int **)malloc(SIZE*SIZE*sizeof(int *));
	for(int i = 0; i < SIZE*SIZE; i++){
		laby[i] = (int *)malloc(SIZE*SIZE*sizeof(int));
		for(int j = 0; j < SIZE*SIZE; j++){
			laby[i][j] = 0;
}
	}
	return laby;
}

void showLaby(int **laby){
	for(int i = 0; i < SIZE*SIZE; i++){
		for(int j = 0; j < SIZE*SIZE; j++){
			printf("%d ", laby[i][j]);
		}
		printf("\n");
	}
}

void loadLaby(int **laby){
	for(int i = 0; i < SIZE-1; i++){
		laby[i][i+1] = 1;
		laby[SIZE*i][SIZE*(i+1)] = 1;
		laby[SIZE*(SIZE-1)+i][SIZE*(SIZE-1)+i+1] = 1;
		laby[SIZE*i-1+SIZE][SIZE*(i+1)-1+SIZE] = 1;
	}
	laby[0][5] = 0;
	laby[19][24] = 0;
	laby[2][7] = 1;
	laby[5][6] = 1;
	laby[8][13] = 1;
	laby[11][12] = 1;
	laby[12][13] = 1;
	laby[15][16] = 1;
	laby[12][17] = 1;
	laby[18][19] = 1;
	laby[17][22] = 1;

}
