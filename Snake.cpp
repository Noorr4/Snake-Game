#include<iostream>
#include "Snake.h"
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
