#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
using namespace std;
struct Node {
    int x;
    int y;
    Node *next;
};

class Snake {
    private:
        Node *head;
        Node *tail;
        int length;

    public:
        Node* gethead();
        int getheadX();
        int getheadY();
        Snake();
        void insertatend(int newX,int newY);
        void deleteattail();
        void movesnake(char direction);
        void displaysnake();
        void movesnake(char direction,bool grow);
        
        // Utility for display & collision
        vector<Node*>getBody();
        
        void grow();
};

#endif

