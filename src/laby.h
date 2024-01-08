/* name : laby.h
 * author : matheo thomas
 * date : 14-12-23
 */

#ifndef laby_h 
#define laby_h


/* Functions definitions */
int **initLaby(int SIZE);

void showLaby(int **laby, int SIZE);

void loadLaby(int **laby, int SIZE);

void genLaby(int **laby, int SIZE);

void prepLaby(int **laby, int SIZE);

void genLabyDepth(int **laby, int *visited, int SIZE, int n);

void mixArray(int *tab, int SIZE);

void genLabyKruskal(int **laby, int SIZE);

#endif

