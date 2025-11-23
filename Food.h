#ifndef FOOD_H
#define FOOD_H

#include "Snake.h"

class Food {
    public:
        int foodX;
        int foodY;
        void generateFood(Snake &snake, int gridWidth, int gridHeight);
};

#endif

