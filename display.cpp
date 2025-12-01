#include <iostream>
#include <windows.h>
#include "Snake.h"
#include "Food.h"
using namespace std;

void hideCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void showCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void clearScreen() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    
    FillConsoleOutputCharacter(hStdOut, ' ', cellCount, coord, &count);
    FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, coord, &count);
    SetConsoleCursorPosition(hStdOut, coord);
}

void moveCursorToTop() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(hOut, pos);
}

void display(Snake &snake, Food &food, int gridWidth, int gridHeight, int score,int Highscore) {
    moveCursorToTop();

    cout << "Score: " << score << endl;
    cout<<"the high score is :"<<Highscore<<endl;
    cout << "====================" << endl;
    cout << endl;

    for (int y = 0; y < gridHeight; y++) {
        for (int x = 0; x < gridWidth; x++) {
            if (x == food.foodX && y == food.foodY)
                cout << "F";
            else if (x == snake.getheadX() && y == snake.getheadY())
                cout << "H";
            else if (snake.isOnBody(x, y))
                cout << "O";
            else
                cout << ".";
        }
        cout << "\n";
    }
    cout << "Controls: W=Up, S=Down, A=Left, D=Right, X=Exit" << endl;
}
