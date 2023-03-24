#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct ListNode {
	int data;
	struct ListNode *next;
} Node;

int is_EmptyStack (Node *top);
void push (Node **top, int data);
int pop (Node **top);
int peek_Stack(Node *s);
int	get_random();
void Show_stack(Node **s);
int count_stack(Node **s);

int main(){
	Node *s = NULL;
	int random = 0;
	Show_stack(&s);

	for(int i = 1; i <= 5; i++){
		random = get_random();
		push(&s, random);
	}
	Show_stack(&s);

	pop(&s);
	pop(&s);
	Show_stack(&s);

}

int is_EmptyStack (Node *top){
	return (top == NULL);
}

void push (Node **top, int data){
	Node *new_Node = NULL;
	new_Node = (Node *)malloc(sizeof(Node));
	if (new_Node == NULL){
		printf("error : Memory allocation failed.\n");
		return ;
	}
	new_Node->next = *top;
	new_Node->data = data;
	*top = new_Node;
	printf("%d pushed to stack\n", data);
}

int pop (Node **top){
	Node *tmp = NULL;
	int pop_Data = 0;
	if (is_EmptyStack(*top)){
		printf("Stack is empty..\n");
		return (INT_MIN);
	}
	else{
		tmp = *top;
		pop_Data = tmp->data;
		*top = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	printf("Pop value : %d\n", pop_Data);
	return (pop_Data);
}

int	get_random(){
	int from = 1;
	int to = 50;
	int value;

	value = rand() % (to - from + 1) + from;
	return (value);
}

void Show_stack(Node **s){
	int count = 0;
	Node *current = *s;

    if (is_EmptyStack(*s)){
        printf("stack is empty...\n");
    } else{
        printf("\n[Show Stack]\n");
        while (current != NULL)
        {
			if(current->next != NULL)
				printf("%d, ", current->data);
			else
        		printf("%d", current->data);
			current = current->next;
			count++;
        }
		printf("\n*size of the Stack : %d\n", count);
    }
}