#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0
#define ERROR -1
typedef int element;

typedef struct deque{
	element data[MAX_SIZE];
	int front;
	int rear;
} deque;

void init_deque(deque *dq);
int is_empty(deque *dq);
int is_full(deque *dq);
element get_rear(deque *dq);
element get_front(deque *dq);
void add_front(deque *dq, element data);
void add_rear(deque *dq, element data);
element delete_front(deque *dq);
element delete_rear(deque *dq);
void print_deque(deque *dq);


int main() {
    deque dq;
	int i = 0;
    init_deque(&dq);

	printf("# ADD FRONT\n\n");
	for(i = 0; i < 3; i++){
		add_front(&dq, i);
		print_deque(&dq);
	}

	// printf("\n# DELETE REAR\n\n");
	// for(i = 0; i < 3; i++){
	// 	delete_rear(&dq);
	// 	print_deque(&dq);
	// }

	printf("\n# ADD REAR\n\n");
	for(i = 0; i < 3; i++){
		add_rear(&dq, i);
		print_deque(&dq);
	}

	// printf("\n# DELETE FRONT\n\n");
	// for(i = 0; i < 3; i++){
	// 	delete_front(&dq);
	// 	print_deque(&dq);
	// }
	return 0;
}

void init_deque(deque *dq) {
	dq->front = 0;
	dq->rear = 0;
}

int is_empty(deque *dq) {
	if (dq->front == dq->rear) return TRUE;
	else return FALSE;
}

int is_full(deque *dq) {
	if (((dq->rear + 1) % MAX_SIZE) == dq->front) return TRUE;
	else return FALSE;
}

element get_rear(deque *dq) {
	if (is_empty(dq)){
		printf("failed rear : queue is empty..\n");
		return ERROR;
	}
	return dq->data[dq->rear];
}

element get_front(deque *dq) {
	if (is_empty(dq)){
		printf("failed get : queue is empty..\n");
		return ERROR;
	}
	return dq->data[dq->front];
}

void add_front(deque *dq, element data){
	if (is_full(dq)){
		printf("failed add f : queue is full..\n");
		return ;
	}
	dq->data[dq->front] = data;
	dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
}

void add_rear(deque *dq, element data) {
	if (is_full(dq)){
		printf("failed add r: queue is full..\n");
		return ;
	}
	dq->rear = (dq->rear + 1) % MAX_SIZE; //MAX_SIZE가 식 보다 크다면 정상적으로 rear + 1.
	dq->data[dq->rear] = data;
}

element delete_front(deque *dq) {
	element tmp;
	if (is_empty(dq)){
		printf("failed delete : queue is empty..\n");
		return ERROR;
	}
	tmp = get_front(dq);
	dq->front = (dq->front + 1) % MAX_SIZE;
	return tmp;
}

element delete_rear(deque *dq){
	element tmp;
	if (is_empty(dq)){
		printf("failed delete : queue is empty..\n");
		return ERROR;
	}
	tmp = get_rear(dq);
	dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
	return tmp;
}

void print_deque(deque *dq){
	if (is_empty(dq)){
		printf("failed print. queue is empty.\n");
		return ;
	}
	int i = (dq->front + 1) % MAX_SIZE;
	printf("deque(f = %d, r = %d)\n", dq->data[dq->front], dq->data[dq->rear]);
	while (i != dq->rear){
		printf("%d | ", dq->data[i]);
		i = (i + 1) % MAX_SIZE;
	}
	printf("%d\n", dq->data[i]);
}
