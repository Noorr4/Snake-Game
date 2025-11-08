struct Node{
	Node *next;
	int x;
	int y;
};
class Snake{
	private:
		Node *head; //front of snake
		Node *tail; //tail of the snake
		int length; //counter
	
	public:
		Snake();
		void insertatend(int newX,int newY);
		void deleteattail();
		void movesnake(char direction);
		void displaysnake();
};
