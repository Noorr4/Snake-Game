#include<iostream>
#include "Snake.h"
#include "Food.h"
#include <cstdlib> //for random
#include <ctime> //to seed random
using namespace std;
void Food::generateFood(Snake &snake, int gridWidth, int gridHeight)
{
    int attempts = 0;

    while (true)
    {
        // GENERATE RANDOM FOOD POSITION
        foodX = rand() % gridWidth;
        foodY = rand() % gridHeight;

        Node *temp = snake.gethead();
        bool collides = false;

        while (temp != NULL)
        {
            if (temp->x == foodX && temp->y == foodY)
            {
                collides = true;//collision found generate new coordinates 
				//the food generation the should not touch the body of the loop intially
                break;
            }
            temp = temp->next;
        }

        if (!collides)
        {
            return; // ? Food generated successfully
        }

        attempts++;
        if (attempts > gridWidth * gridHeight)
        {
            cout << "?? No space left for food!" << endl;
            return;
        }
    }
}


