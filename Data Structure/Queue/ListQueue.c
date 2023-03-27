#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

typedef struct Queue{
	Node *front;
	Node *rear;
} Queue;

void Que_initialize(Queue *q);
int is_Empty(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void print_Queue(Queue *q);

int main(){
	Queue q;

	Que_initialize(&q);
	print_Queue(&q);

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	print_Queue(&q);

	dequeue(&q);
	dequeue(&q);
	print_Queue(&q);
	dequeue(&q);
	dequeue(&q);
	print_Queue(&q);

}

// Queue 초기화 함수
void Que_initialize(Queue *q){		
	q->front = NULL;
	q->rear = NULL;
}

// Queue가 비어있는지 확인하는 함수
int is_Empty(Queue *q){
	return (q->front == NULL);
}

// 큐에 데이터를 삽입하는 함수
void enqueue(Queue *q, int data){
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (!new_node){
		printf("error : Memorry allocation failed.\n");
		return ;
	}
	new_node->data = data;
	new_node->next = NULL;
	if (is_Empty(q)){
		q->front = new_node;		// 큐가 비어있다면 front와 rear를 새로운 노드로 설정
		q->rear = new_node;
	}
	else{ 
		q->rear->next = new_node;		// 큐가 비어있지 않다면 rear 노드의 next를 새로운 노드로 설정하고 rear를 새로운 노드로 업데이트
		q->rear = new_node;
	}
}

int dequeue(Queue *q){
	Node *tmp = NULL;
	int r_data = 0;
	if (is_Empty(q)){
		printf("Queue is empty..");
		return (-1);
	}
	tmp = q->front;		// front 노드를 임시로 저장한 후 front를 front의 next_node로 업데이트
	r_data = tmp->data;
	q->front = tmp->next;
	free(tmp);
	if (q->front == NULL) 
		q->rear = NULL;		// front를 업데이트한 후 큐가 비어있다면 rear도 NULL로 설정
	printf("dequeue value : %d \n", r_data);
	return (r_data);
}

void print_Queue(Queue *q){
	Node *tmp = NULL;
	if (is_Empty(q))
		printf("Queue is empty..\n");
	else {
		for (tmp = q->front; tmp != NULL; tmp = tmp->next)
			printf("%d -> ", tmp->data);
		printf("NULL\n");
	}
}