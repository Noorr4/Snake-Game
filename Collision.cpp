#include "Collision.h"
#include<iostream>
using namespace std;
// Check if snake hits a wall
bool Collision::checkWallCollision(int headX, int headY, int gridWidth, int gridHeight) {
    if (headX < 0 || headX >= gridWidth || headY < 0 || headY >= gridHeight) {
        return true;
    }
    return false;
}

// Check if snake bites itself
bool Collision::checkselfCollision(Snake snake) {

    Node* head = snake.gethead();
    int headX = head->x;
    int headY = head->y;

    Node* temp = head->next;

    while (temp !=NULL) {
        if (temp->x == headX && temp->y == headY) {
            return true;   // self collision
        }
        temp = temp->next;
    }

    return false;
}

