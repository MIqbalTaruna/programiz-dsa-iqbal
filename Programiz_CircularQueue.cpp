#include <iostream>
#define max 5
using namespace std;

class Queue{
	private:
		int items[max], front, rear;
	public:
		Queue(){
			front = -1;
			rear = -1;
		}
		
		bool isFull(){
			if(front == 0 && rear == max - 1)
				return true;
			if(front == rear + 1)
				return true;
			return false;
		}
		
		bool isEmpty(){
			return front == -1;
		}
		
		void enqueue(int newItem){
			if(isFull())
				cout << "FULL" << endl;
			else {
				if(isEmpty())
					front = 0;
				if(rear == max - 1)
					rear = 0;
				else 
					rear++;
				items[rear] = newItem;
				cout << "Enqueue : " << newItem << endl;
			}
		}
		
		int dequeue(){
			if(isEmpty())
				cout << "EMPTY" << endl;
			else {
				int temp = items[front];
				if(front == rear){
					front = -1;
					rear = -1;					
				}
				else 
					front++;
				cout << "Dequeue : " << temp << endl;
				return temp;
			}
		}
		
		void display(){
			if(isEmpty())
				cout << "EMPTY" << endl;
			else {
				if(rear < front){
					for(int i = front; i < max; i++)
						cout << items[i] << " ";
					for(int i = 0; i <= rear; i++)
						cout << items[i] << " ";
				}
				for(int i = front; i <= rear; i++)	
					cout << items[i] << " ";
				cout << endl;
			}
		}
};

int main(){
	Queue q1;
	
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	
	q1.display();
	
	q1.dequeue();
	q1.dequeue();
	
	q1.display();
	
	q1.enqueue(6);
	q1.enqueue(7);
	
	q1.display();
}
