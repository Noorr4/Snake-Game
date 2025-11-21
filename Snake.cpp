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
	// grow = add new block without removing tail
    movesnake('X', true);  // We will NOT use 'X' direction; main will call grow after move
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
void Snake::movesnake(char direction)
{
    movesnake(direction, false);   
}
void Snake::movesnake(char direction,bool grow)
{
	int newX=head->x;
	int newY=head->y;
	
	if(direction=='U')
	{
		newY--;
	}
	else if(direction=='D')
	{
		newY++;
	}
	else if(direction=='L')
	{
		newX--;
	}
	else if(direction=='R')
	{
		newX++;
	}
	// create new head node (we use insertatend to add a block at tail side of your linked list)
    // but your design uses head at front and tail at end; keeping your functions:
    insertatend(newX,newY);
    if(!grow)
    {
    	deleteattail();
	}
	
}

