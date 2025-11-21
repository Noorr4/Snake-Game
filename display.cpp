#include <iostream>
#include <vector>
#include "Snake.h"
#include "Food.h"
#include "display.h"
using namespace std;

void display(Snake &snake, Food &food, int gridWidth, int gridHeight, int score)
{
    system("cls");  // Clear screen (Windows)

    // STEP 1 — Create 2D grid filled with '.'
    vector<vector<char> > grid(gridHeight, vector<char>(gridWidth, '.'));

    // STEP 2 — Place Snake Body
    Node* cur = snake.gethead();
    while (cur != NULL)
    {
        int x = cur->x;
        int y = cur->y;

        if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight)
        {
            grid[y][x] = 'O';   // Snake body
        }

        cur = cur->next;
    }

    // STEP 3 — Mark Snake Head separately
    Node* head = snake.gethead();
    if (head != NULL)
    {
        int hx = head->x;
        int hy = head->y;

        if (hx >= 0 && hx < gridWidth && hy >= 0 && hy < gridHeight)
        {
            grid[hy][hx] = '@';   // Snake Head
        }
    }

    // STEP 4 — Place Food
    int fx = food.foodX;
    int fy = food.foodY;

    if (fx >= 0 && fx < gridWidth && fy >= 0 && fy < gridHeight)
    {
        grid[fy][fx] = '*';  // Food
    }

    // STEP 5 — Print Grid Row by Row
    for (int y = 0; y < gridHeight; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            cout << grid[y][x];
        }
        cout << endl;
    }

    // STEP 6 — Print score & instructions
    cout << "\nScore: " << score << endl;
    cout << "Use Arrow Keys or WASD | P = Pause | Q = Quit\n";
}

