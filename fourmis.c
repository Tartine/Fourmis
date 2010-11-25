#include <stdlib.h>
#include <stdio.h>
#include "fourmis.h"
#include <stdbool.h>

/* Table de v�rit�
   
   1    2    3

   4         5
   
   6    7    8
*/

unsigned short pheromoneFourmil[X][Y];
unsigned short pheromoneFood[X][Y] = {0};
unsigned short food[X][Y] = {0};


void matrix_init(){
	// TODO use pointers
	int i,j;

	// antfarm init, antfarm is in the right-bottom corner
	for(i=0; i < X; i++){
		for(j=0; j < Y; j++){
			pheromoneFourmil[i][j] = i + j;
		}
	}
	//now we decrease pheromone power paste the antfarm
	for(i=0; i < X-ANTFARM_X; i++){
		for(j=0; j < Y-ANTFARM_Y; i++){
			pheromoneFourmil[i+ANTFARM_X][j+ANTFARM_J] -= (i+j)*2;
		}
	}

	// we now init the sugar in itself
	for(i=FOOD_X; i < FOOD_X+FOOD_S_X; i++){
		for(j=FOOD_Y; j < FOOD_Y+FOOD_S_Y; j++){
			food[x][y] = 1;
		}
	}
}

// a function that return the movement the ant must do when it has
// some food. (See the "table of v�rit�" at the beginning).
short moveWithFood(unsigned short x, unsigned short y){
	short direction = 0;
	short current = pheromoneFourmil[x][y];

	//check for position 1,2,3,4,5,6,7,8...
	if(pheromoneFourmil[x-1][y-1] > current){
		current = pheromoneFourmil[x-1][y-1];
		direction = 1;
	}
	if(pheromoneFourmil[x-1][y] > current){
		current = pheromoneFourmil[x-1][y];
		direction = 2;
	}
	if(pheromoneFourmil[x-1][y+1] > current){
		current = pheromoneFourmil[x-1][y+1];
		direction = 3;
	}
	if(pheromoneFourmil[x][y-1] > current){
		current = pheromoneFourmil[x][y-1];
		direction = 4;
	}
	if(pheromoneFourmil[x][y+1] > current){
		current = pheromoneFourmil[x][y+1];
		direction = 5;
	}
	if(pheromoneFourmil[x+1][y-1] > current){
		current = pheromoneFourmil[x+1][y-1];
		direction = 6;
	}
	if(pheromoneFourmil[x+1][y] > current){
		current = pheromoneFourmil[x+1][y];
		direction = 7;
	}
	if(pheromoneFourmil[x+1][y+1] > current){
		current = pheromoneFourmil[x+1][y-1];
		direction = 8;
	}

	return direction;
}


short moveWithoutFood(unsigned short x, unsigned short y, unsigned short lastMovement){
	// So, for the movements, we'll use some random stuff and ponderate it,
	// many conditions....we must add a check too to check if there is any 
	// pheromones near the ant and if there is any, follow them.



void antMove (ant_t * ant){
	// if the ant has some food, it must go to the antfarm
	if(ant->food = true){
		ant->lastMovement = moveWithFood(ant->x, ant->y);
	}
	else {
		ant->lastMovement = moveWithoutFood(ant->x, ant->y, ant->lastMovement);
	}
}

void main(void){};
