#ifndef COLLISION_H
#define COLLISION_H
#include "Snake.h"

class Collision {
    public:
        // Checks if the snake hits a wall
        bool checkWallCollision(int headX, int headY, int gridWidth, int gridHeight);
        
        // Checks if the snake bites itself
        bool checkselfCollision(Snake snake);
};

#endif  // This should be at the very end
