#include<iostream>
#include "Snake.h"
#include "Food.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Add this function to initialize random seed
void initRandom() {
    static bool initialized = false;
    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }
}

void Food::generateFood(Snake &snake, int gridWidth, int gridHeight) {
    initRandom(); // Initialize random seed
    
    int attempts = 0;
    int maxAttempts = gridWidth * gridHeight * 2; // Increased attempts

    while (attempts < maxAttempts) {
        foodX = rand() % gridWidth;
        foodY = rand() % gridHeight;

        Node *temp = snake.gethead();
        bool collides = false;

        while (temp != NULL) {
            if (temp->x == foodX && temp->y == foodY) {
                collides = true;
                break;
            }
            temp = temp->next;
        }

        if (!collides) {
            return;
        }
        attempts++;
    }

    // Fallback: find any empty spot linearly
    for (int y = 0; y < gridHeight; y++) {
        for (int x = 0; x < gridWidth; x++) {
            if (!snake.isOnBody(x, y) && 
                !(x == snake.getheadX() && y == snake.getheadY())) {
                foodX = x;
                foodY = y;
                return;
            }
        }
    }
}
