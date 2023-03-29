#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct Deque{
	Node *front;
	Node *rear;
	int size;
} Deque;

#define ERROR -1

void init_Deque(Deque *dq);
int is_empty(Deque *dq);
void add_front(Deque *dq, int data);
void add_rear(Deque *dq, int data);
int remove_front(Deque *dq);
int remove_rear(Deque *dq);
void print_deque(Deque *dq);
int pick_size(Deque *dq);

int main()
{
	Deque dq;
	
	init_Deque(&dq);

	add_front(&dq, 20);
	add_front(&dq, 10);
	add_rear(&dq, 30);
	add_rear(&dq, 40);
	
	print_deque(&dq);
	printf("deque size : %d\n", pick_size(&dq));
	printf("remove front : %d\n", remove_front(&dq));
	printf("remove rear : %d\n", remove_rear(&dq));
	
	print_deque(&dq);
	printf("deque size : %d\n", pick_size(&dq));

}
//리스트는 크기가 가변적이기에 full이 필요x

void init_Deque(Deque *dq)
{
	dq->front = NULL;
	dq->rear = NULL;
	dq->size = 0;
}

int is_empty(Deque *dq)
{
	return (dq->size == 0);
}

void add_front(Deque *dq, int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if(!new_node)
		return ;
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = dq->front; 	//새로운 노드의 다음 노드는 front가 가르키는 노드.
	if (is_empty(dq)) 
		dq->rear = new_node;
	else
		dq->front->prev = new_node; 	//맨앞의 노드의 이전 자리에 new_node가 추가됨.
	dq->front = new_node; 		//front가 새로운 노드를 가르키도록
	dq->size++;
}

void add_rear(Deque *dq, int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->prev = dq->rear;	//새로운 노드의 이전 노드는 rear가 가르키는 노드
	new_node->next = NULL;
	if (is_empty(dq))
		dq->front = new_node; //deque가 비어있을 경우, rear도 새로운 노드를 가르키도록 함
	else
		dq->rear->next = new_node; //맨 뒤의 노드의 다음 자리에 new_node가 추가됨.
	dq->rear = new_node;	//rear가 새로운 노드를 가르키도록
	dq->size++;
}

int remove_front(Deque *dq)
{
	Node *tmp;
	int data;
	if (is_empty(dq)) //덱이 비어있는 경우.
	{
		printf("deque is empty..\n");
		return ERROR;
	}
	tmp = dq->front;	//tmp에 front가 가르키는 노드의 주소를 저장
	data = tmp->data;	//삭제할 노드의 데이터를 data에 저장
	dq->front = tmp->next;	//rear의 이전 값을 가르키도록
	if (dq->front == NULL)
		dq->rear = NULL;	// 삭제된 노드가 마지막 노드일 경우
	else
		dq->front->prev = NULL; // front 노드의 prev 값을 NULL로 초기화
	free(tmp);
	tmp = NULL;
	dq->size--;
	return data;
}

int remove_rear(Deque *dq)
{
	Node *tmp;
	int data;
	if (is_empty(dq)) //덱이 비어있는 경우.
	{
		printf("deque is empty..\n");
		return ERROR;
	}
	tmp = dq->rear;		//삭제할 노드를 tmp에 저장
	data = tmp->data;	//삭제할 노드의 데이터를 data에 저장
	dq->rear = tmp->prev; //rear의 이전 값을 가르키도록
	if (dq->rear == NULL) // 삭제된 노드가 마지막 노드일 경우
		dq->front = NULL;
	else
		dq->rear->next = NULL;
	free(tmp);
	tmp = NULL;
	dq->size--;
	return data;
}

void print_deque(Deque *dq)
{
    if (is_empty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    Node *tmp = dq->front;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");
}

int pick_size(Deque *dq)
{
	return(dq->size);
} 