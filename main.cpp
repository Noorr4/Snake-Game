#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Snake.h"
#include "Food.h"
#include "Collision.h"
#include "display.h"
#include <fstream>
using namespace std;

// compute next head position without moving the snake
void computeNextPos(int &nx, int &ny, int headX, int headY, char direction) {
    nx = headX;
    ny = headY;
    if (direction == 'U') ny--;
    else if (direction == 'D') ny++;
    else if (direction == 'L') nx--;
    else if (direction == 'R') nx++;
}
int HighScore()
{
	ifstream file("Highscore.txt");
	int score=0;
	if(file.is_open())
	{
		file>>score;
		file.close();
	}
	return score;
}
void SaveScore(int score)
{
	ofstream file("Highscore.txt");
	if(file.is_open())
	{
		file<<score;
		file.close();
	}
}
int Highscore=HighScore(); //global variable

bool gameLoop() {
    const int GRID_WIDTH = 30;
    const int GRID_HEIGHT = 20;
    int score = 0;
    
    bool gameOver = false;
    bool paused = false;

    Snake snake;
    Food food;
    Collision collision;

    // first food
    food.generateFood(snake, GRID_WIDTH, GRID_HEIGHT);

    char direction = 'R';
    char lastDirection = 'R';

    hideCursor();

    // first display so border/grid is visible
    display(snake, food, GRID_WIDTH, GRID_HEIGHT, score,Highscore);

    const int FRAME_DELAY_MS = 140; // adjust to make it slower/faster

    while (!gameOver) {
        // INPUT: support arrow keys and WASD (YOUR ORIGINAL INPUT CODE)
        if (_kbhit()) {
            int key = _getch();

            // arrow key sequences begin with 0 or 224 depending on compiler
            if (key == 0 || key == 224) {
                int arrow = _getch();
                if (arrow == 72 && lastDirection != 'D') direction = 'U'; // Up
                else if (arrow == 80 && lastDirection != 'U') direction = 'D'; // Down
                else if (arrow == 75 && lastDirection != 'R') direction = 'L'; // Left
                else if (arrow == 77 && lastDirection != 'L') direction = 'R'; // Right
            } else {
                // convert lowercase to uppercase
                if (key >= 'a' && key <= 'z') key -= 32;

                if (key == 'W' && lastDirection != 'D') direction = 'U';
                else if (key == 'S' && lastDirection != 'U') direction = 'D';
                else if (key == 'A' && lastDirection != 'R') direction = 'L';
                else if (key == 'D' && lastDirection != 'L') direction = 'R';
                else if (key == 'P') paused = !paused;
                else if (key == 'X') { gameOver = true; break; }
            }
        }

        if (paused) {
            // simple paused screen
            showCursor();
            clearScreen();
            cout << "GAME PAUSED\nPress P to resume or X to quit\n";
            
            // Wait for valid input to resume
            while (true) {
                if (_kbhit()) {
                    int k = _getch();
                    if (k == 'P' || k == 'p') {
                        paused = false;
                        break;
                    } else if (k == 'X' || k == 'x') {
                        gameOver = true;
                        break;
                    }
                }
                Sleep(100);
            }
            
            hideCursor();
            display(snake, food, GRID_WIDTH, GRID_HEIGHT, score,Highscore);
            continue;
        }

        // compute next head position without moving (YOUR ORIGINAL COLLISION CHECK)
        int headX = snake.getheadX();
        int headY = snake.getheadY();
        int nx, ny;
        computeNextPos(nx, ny, headX, headY, direction);

        // check wall collision at next position
        if (collision.checkWallCollision(nx, ny, GRID_WIDTH, GRID_HEIGHT)) {
            gameOver = true;
            break;
        }

        // check if next position contains food
        bool willGrow = (nx == food.foodX && ny == food.foodY);

        // move snake (grow or normal)
        if (willGrow) {
            snake.movesnake(direction, true);
            score += 10;

            food.generateFood(snake, GRID_WIDTH, GRID_HEIGHT);
        } else {
            snake.movesnake(direction, false);
        }

        // after moving, check self-collision
        if (collision.checkselfCollision(snake)) {
            gameOver = true;
            break;
        }

        lastDirection = direction;

        // display
        display(snake, food, GRID_WIDTH, GRID_HEIGHT, score,Highscore);

        Sleep(FRAME_DELAY_MS);
    }
    
    // Game over display
    showCursor();
    clearScreen();
    cout << "GAME OVER!\n";
    cout << "Final Score: " << score << endl;
    if(score>Highscore)
    {
    	Highscore=score;
    	cout<<"the new High score is:"<<Highscore<<endl;
    	SaveScore(Highscore);
	}
	else
	{
		cout<<"The High score is :"<<Highscore<<endl;
	}
    
    return false; // false means game ended (not normal exit)
}

int main() {
    srand((unsigned)time(0)); // Initialize random seed once at start
    
    bool playAgain = true;
    
    while (playAgain) {
        clearScreen();
        cout << "=== SNAKE GAME ===" << endl;
        cout << "Controls: Arrow Keys or WASD to move" << endl;
        cout<<"The Highscore is:"<<Highscore<<endl;
        cout << "P = Pause, X = Exit" << endl;
        cout << "Starting game in 2 seconds..." << endl;
        Sleep(2000);
        
        bool normalExit = gameLoop();
        
        if (normalExit) {
            cout << "Game exited normally." << endl;
        }
        
        cout << "\nPlay again? (Y/N): ";
        char choice;
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        playAgain = (toupper(choice) == 'Y');
    }
    
    showCursor();
    cout << "Thanks for playing!" << endl;
    return 0;
}
