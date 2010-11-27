#include  <stdlib.h>
#include  <stdio.h>
#include  "fourmis.h"
#include  <stdbool.h>
#include  <time.h>
#include  <string.h>

/* Table de vérité
   
   1    2    3

   8         4
   
   7    6    5
*/

unsigned short pheromoneFourmil[X][Y];
unsigned short pheromoneFood[X][Y];
unsigned short food[X][Y];


void matrix_init(void){
	// TODO use pointers
  
  // initialize pheromoneFood and food to 0 using memset :
  memset(pheromoneFood, 0, sizeof(pheromoneFood));
  memset(food, 0, sizeof(food));

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
			pheromoneFourmil[i+ANTFARM_X][j+ANTFARM_Y] -= (i+j)*2;
		}
	}

	// we now init the sugar in itself
	for(i=FOOD_X; i < FOOD_X+FOOD_S_X; i++){
		for(j=FOOD_Y; j < FOOD_Y+FOOD_S_Y; j++){
			food[i][j] = 1;
		}
	}
}

// a function that return the movement the ant must do when it has
// some food. (See the "table of vérité" at the beginning).
short moveWithFood(unsigned short x, unsigned short y){
	short direction = 0;
	short current = pheromoneFourmil[x][y];

	//check for position 1,2,3,8,4,7,6,5...
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
		direction = 8;
	}
	if(pheromoneFourmil[x][y+1] > current){
		current = pheromoneFourmil[x][y+1];
		direction = 4;
	}
	if(pheromoneFourmil[x+1][y-1] > current){
		current = pheromoneFourmil[x+1][y-1];
		direction = 7;
	}
	if(pheromoneFourmil[x+1][y] > current){
		current = pheromoneFourmil[x+1][y];
		direction = 6;
	}
	if(pheromoneFourmil[x+1][y+1] > current){
		current = pheromoneFourmil[x+1][y-1];
		direction = 5;
	}

	return direction;
}



short moveWithoutFood(unsigned short x, unsigned short y, unsigned short lastMovement){

	// So, for the movements, we'll use some random stuff and ponderate it,
	// many conditions....we must add a check too to check if there is any 
	// pheromones near the ant and if there is any, follow them.
  
  // So, here we are, we first init random seed with the current
  // // So, here we are, we first init random seed with the current time
  srand(time(NULL));
  short i;
  const unsigned short max_ponderate = 4;
  unsigned char ponderate[8] = {0};

  // for numbers >= lastMovement
  for ( i = 0; i <= 4 ; i++) {
    ponderate[(lastMovement+i-1)%8] = max_ponderate - i;
  }

  // now for numbers < lastMovement
  for ( i = 0; i <= 2; i++) {
    ponderate[(lastMovement-i+4)%8] = max_ponderate - (i+1);
  }


  return EXIT_SUCCESS;
}


void antMove (ant_t * ant){
	// if the ant has some food, it must go to the antfarm
	if(ant->food == true){
		ant->lastMovement = moveWithFood(ant->x, ant->y);
	}
	else {
		ant->lastMovement = moveWithoutFood(ant->x, ant->y, ant->lastMovement);
	}
}

int main(void){
  return EXIT_SUCCESS;

};
