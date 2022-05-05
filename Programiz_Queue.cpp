#include <iostream>
#define max 5
using namespace std;

struct Queue{
	int items[max];
	int front;
	int rear;
};

typedef struct Queue queue;

void createEmptyQueue(queue *q){
	q->front = -1;
	q->rear = -1;
}

bool isEmpty(queue *q){
	return q->front == -1;
}

bool isFull(queue *q){
	return q->rear == max - 1;
}

void enqueue(queue *q, int newItem){
	if(isFull(q)){
		cout << "FULL" << endl;
	} 
	else {
		if(isEmpty(q))
			q->front = 0;		
		q->rear++;
		q->items[q->rear] = newItem;		
	}
}

int dequeue(queue *q){
	int item;
	if(isEmpty(q)){
		cout << "EMPTY" << endl;
		return -1;
	}
	else {
		item = q->items[q->front];
		if(q->front >= q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else {
			q->front++;
		}
		return item;
	}
}

void display(queue *q){
	if(isEmpty(q))
		cout << "EMPTY" << endl;
	else {
		cout << "Queue : ";
		for(int i = q->front; i <= q->rear; i++)
			cout << q->items[i] << " ";
	}
	cout << endl;
}

int main(){
	queue *q = new queue();
	createEmptyQueue(q);
	
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	
	display(q);
	
	dequeue(q);
	dequeue(q);
	
	display(q);
	
	enqueue(q, 6);
}
