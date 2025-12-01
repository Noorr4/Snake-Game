#ifndef DISPLAY_H
#define DISPLAY_H

#include "Snake.h"
#include "Food.h"

void display(Snake &snake, Food &food, int gridWidth, int gridHeight, int score,int Highscore);
void hideCursor();
void showCursor();
void clearScreen();

#endif

