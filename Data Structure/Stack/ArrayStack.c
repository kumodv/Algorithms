#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

int stack_Array[CAPACITY];
int top = -1; //top of Stack index

// Check if the stack is full
int is_Full(){
	if (top >= CAPACITY - 1){
		printf("Error : Stack is Full\n");
		return 1;
	}
	return 0;
}

// Check if the stack is empty
int is_Empty(){
	if (top == -1){
		printf("Error : Stack is Empty\n");
		return 1;
	}
	return 0;
}

// Push an element onto the top of the stack
void Push(int data){
	if (!is_Full()){
		top++;
		stack_Array[top] = data;
	}
}

// Pop the top element from the stack
int Pop(){
    if(!is_Empty()){
        return stack_Array[top--];
    }
	return (-1);
}

// Print the stack elements
void print_Stack(){
	int i;
	for(i = 0; i <= top; i++){
		printf("%d ", stack_Array[i]);
	}
	printf("\n");
}

int main(){
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	print_Stack();
	Pop();
	print_Stack();
} 