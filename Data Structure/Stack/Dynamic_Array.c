#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stack{
	int top; //top of array index
	int max_size; // max stack size
	int *data;
} t_stack;

void	Stack_initialize(t_stack *s, int size);
int	is_empty(t_stack *s);
void	push(t_stack *s, int value);
int	pop(t_stack *s);
int peek_stack(t_stack *s);
void	Show_stack(t_stack *s);
int	get_random();
int	is_full(t_stack *s);
int	pop(t_stack *s);

int main(){
	t_stack stack;
	int		random;
	Stack_initialize(&stack, 2);

	Show_stack(&stack); // display initial stack (empty)
	for(int i = 1; i <= 5; i++){ //push 5 random numbers onto the stack
		random = get_random();
		push(&stack, random);
	}
	Show_stack(&stack); //display stack with 5 elements

	pop(&stack);
	pop(&stack);
	Show_stack(&stack); //display stack with 3 elements

	free(stack.data);
	printf("stack is free!\n");
	return (0);
}

void	Stack_initialize(t_stack *s, int size){
	s->top = -1; //set top index to -1 (empty stack)
	s->max_size = size;
	s->data = (int *)malloc(size * sizeof(int)); //allocate memory for stack
}

int	is_empty(t_stack *s){
	if (s->top == -1)
		return (1);
	return (0);
}

int	is_full(t_stack *s){
	return ((s->top == s->max_size - 1) ? 1 : 0);
}

void	push(t_stack *s, int value){
	if (is_full(s)){
		s->max_size *= 2; //if the stack is full, double the stack size and reallocate memory
		s->data = realloc(s->data, sizeof(int) * s->max_size);
		printf("Memory reallocation : Stack is full\n");
		printf("stack size : %d\n", s->max_size);
	}
	s->top++; // increment top index
	s->data[s->top] = value; // add element to the stack
}

int	pop(t_stack *s){
	if (s->top >= 0){
		int value = s->data[s->top];
		s->top--;
		printf("Pop value : %d\n", value);
		return (value);
	}
	printf("Stack is empty T T\n");
	return (0);
}

//function to return the value at the top. Used when viewing top value
int peek_stack(t_stack *s){
	int value = s->data[s->top];
	return (value);
}

void Show_stack(t_stack *s){
    if (is_empty(s)){
        printf("stack is empty...\n");
    } else{
        printf("\n[Show Stack]\n");
        printf("*top of the Stack : %d\n", peek_stack(s));
		printf("*size of the Stack : %d\n", s->max_size);
        printf("[ ");
        for (int i = 0; i <= s->top; i++)
        {
			if(i != s->top)
				printf("%d, ", s->data[s->top-i]);
			else
        		printf("%d", s->data[s->top-i]);
        }
        printf(" ]\n");
    }
}

int	get_random(){
	int from = 1;
	int to = 50;
	int value;

	value = rand() % (to - from + 1) + from;
	return (value);
}
