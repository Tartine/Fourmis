#ifndef FOURMIS
#define FOURMIS
#include <stdbool.h>
#include <stdlib.h>
#define X 640
#define Y 480
#define FOOD_S_X 50
#define FOOD_S_Y 30
#define FOOD_X 50
#define FOOD_Y 50
#define ANTFARM_X (X-20)
#define ANTFARM_Y (Y-20)
#define MAX_RANDOM 10

typedef struct ant {
	unsigned short x;
	unsigned short y;
	unsigned short lastMovement;
	bool food;
} ant_t;

// The function that ponderate the movments
void antMove (ant_t * ant);
void matrix_init(void);
short moveWithFood(unsigned short x, unsigned short y);
short moveWithoutFood(unsigned short x, unsigned short y, unsigned short lastMovement);


#endif
