#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Snake.h"
#include "Food.h"
#include "display.h"
#include <ctime>
using namespace std;

int main()
{
    int gridWidth = 30;
    int gridHeight = 30;
    int score = 0;

    Snake snake;
    Food food;

    // Seed random once
    srand(time(0));

    // Generate first food
    food.generateFood(snake, gridWidth, gridHeight);

    char direction = 'R';  // starts moving Right
    bool gameRunning = true;

    while (gameRunning)
    {
        // INPUT SECTION
        if (_kbhit())
        {
            char ch = _getch();

            if (ch == 'w' || ch == 'W') direction = 'U';
            else if (ch == 's' || ch == 'S') direction = 'D';
            else if (ch == 'a' || ch == 'A') direction = 'L';
            else if (ch == 'd' || ch == 'D') direction = 'R';
            else if (ch == 'q' || ch == 'Q') gameRunning = false;
        }

        // MOVE SNAKE
        snake.movesnake(direction);

        // CHECK IF FOOD EATEN
        if (snake.getheadX() == food.foodX && snake.getheadY() == food.foodY)
        {
            score++;
            snake.grow();
            food.generateFood(snake, gridWidth, gridHeight);
        }

        // DISPLAY GRID
        display(snake, food, gridWidth, gridHeight, score);

        // Delay
        Sleep(120);
    }

    cout << "\nGame Over!\n";
    return 0;
}

