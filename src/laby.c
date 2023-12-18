/* name : laby.c
 * author : matheo thomas
 * date : 14-12-23
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "laby.h"



int **initLaby(int SIZE){
	int **laby = (int **)malloc(SIZE*SIZE*sizeof(int *));
	for(int i = 0; i < SIZE*SIZE; i++){
		laby[i] = (int *)malloc(SIZE*SIZE*sizeof(int));
		for(int j = 0; j < SIZE*SIZE; j++){
			laby[i][j] = 0;
		}
	}
	return laby;
}

void showLaby(int **laby, int SIZE){
	for(int i = 0; i < SIZE*SIZE; i++){
		for(int j = 0; j < SIZE*SIZE; j++){
			printf("%d ", laby[i][j]);
		}
		printf("\n");
	}
}

void loadLaby(int **laby, int SIZE){
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

void genLaby(int **laby, int SIZE){
	srand(time(0));

	for(int i = 0; i < SIZE-1; i++){
		laby[i][i+1] = 1;
		laby[SIZE*i][SIZE*(i+1)] = 1;
		laby[SIZE*(SIZE-1)+i][SIZE*(SIZE-1)+i+1] = 1;
		laby[SIZE*(i+1)-1][SIZE*(i+2)-1] = 1;
	}

	for(int i = 0; i < SIZE-1; i++){
		for(int j = 1; j < SIZE-1; j++){
			laby[i+j*SIZE][i+1+j*SIZE] = rand()%2;
			laby[SIZE*i+j][SIZE*(i+1)+j] = rand()%2;
		}
	}
	laby[0][SIZE] = 0;
	laby[SIZE*(SIZE-1)-1][SIZE*SIZE-1] = 0;

}


void prepLaby(int **laby, int SIZE){
	for(int i = 0; i < SIZE-1; i++){
		for(int j = 0; j < SIZE; j++){
			laby[i+j*SIZE][i+1+j*SIZE] = 1;
			laby[SIZE*i+j][SIZE*(i+1)+j] = 1;
		}
	}
	laby[0][SIZE] = 0;
	laby[SIZE*(SIZE-1)-1][SIZE*SIZE-1] = 0;

}


void genLabyDepth(int **laby, int *visited, int SIZE, int n){
	printf("recursion\n");
	srand(time(0));
	//int *tab = (int *)malloc(4*sizeof(int));
	int tab[4] = { n-1, n+1, n-SIZE, n+SIZE };
	//int i = 0;
	visited[n] = 1;
	int i = 0;
	for(int j = 0; j < 4; j++){
		if(visited[tab[j]] == 0){
			i++;
		}
	}

	int r = rand()%i;
	while(i != 1){
		if(visited[tab[r%i]] == 0){
			laby[n][tab[r%i]] = 0;
			printf("%d\n", tab[r%i]);
			genLabyDepth(laby, visited, SIZE, tab[r%i]);
			i--;
		} else {
			r++;
		}
		printf("loop\n");
	}
}



