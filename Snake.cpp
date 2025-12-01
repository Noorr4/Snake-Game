#include<iostream>
#include "Snake.h"
#include <vector>
using namespace std;
Snake::Snake(){
	Node*newNode=new Node();//For Creating one block of snake in the center of grid
	newNode->x=15;//15 for center
	newNode->y=15;
	head=newNode;
	tail=newNode;
	newNode->next=NULL;
	length=1;
}
Node* Snake::gethead()
{
	return head;
}
void Snake::insertatend(int newX,int newY)
{
	Node*newNode=new Node();
	newNode->x=newX;
	newNode->y=newY;
	
	newNode->next=NULL;
	
	tail->next=newNode;//joining the newNode with the tail of the first block of snake made in constructor
	tail=newNode;
	length++;
}
void Snake::deleteattail()
{
	if(head==NULL)
	{
		return;
	}
	if(head==tail)
	{
		delete head;
		head=tail=NULL;
		length=0;
		return;
	}
	Node*temp=head;
	while(temp->next!=tail)
	{
		temp=temp->next;
	}
	Node*del=tail;
	temp->next=NULL;
	delete del;
	tail=temp;
	length--;
}
void Snake::displaysnake()
{
	if(head==NULL)
	{
		return;
	}
	Node*temp=head;
	while(temp!=NULL)
	{
		cout<<"("<<temp->x<<","<<temp->y<<")";
		if(temp->next != NULL)
        {
            cout << " , ";
        }
		temp=temp->next;
	}
}
int Snake::getheadX()
{
	return head->x;
}
int Snake::getheadY()
{
	return head->y;
}
void Snake::grow()
{
    length++;  
}
void Snake::insertAtHead(int x, int y) {
    Node* n = new Node();
    n->x = x;
    n->y = y;
    n->next = head;  // now compiler knows head
    head = n;

    if (tail == NULL)
        tail = n;
}
vector<Node*> Snake::getBody() {
    vector<Node*> body;
    Node* temp = head;
    while (temp != NULL) {
        body.push_back(temp);
        temp = temp->next;
    }
    return body;
}
bool Snake::isOnBody(int x, int y) {
    // Start from the node after head to avoid checking head itself
    Node* temp = head->next;
    while (temp != NULL) {
        if (temp->x == x && temp->y == y) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void Snake::movesnake(char direction, bool grow)
{
    int newX = head->x;
    int newY = head->y;

    if(direction == 'U') newY--;
    else if(direction == 'D') newY++;
    else if(direction == 'L') newX--;
    else if(direction == 'R') newX++;

    insertAtHead(newX, newY);

    if (!grow)
        deleteattail();
}


