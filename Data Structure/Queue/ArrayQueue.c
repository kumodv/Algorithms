#include <stdio.h>

#define MAX 100

int que_arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
	if (rear == MAX - 1) {
		printf("Queue is full..\n");
		return ;
	}
	que_arr[rear] = data;
	printf("init value : %d\n", que_arr[rear]);
	rear += 1;
}

void dequeue() {
	if (front == rear) {
		printf("Queue is empty..\n");
		return ;
	}
	else{
		printf("Element deleted from the Queue : %d\n", que_arr[front]);
		front += 1;
	}
}

int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
}