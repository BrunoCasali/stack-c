#include <stdlib.h>
#include <stdio.h>

#define MAX 50

struct stack{
	int pointer;
	float value[MAX];
};

typedef struct stack Stack;

Stack* new(){
	Stack* s = (Stack*) malloc(sizeof(Stack));
	s-> pointer = 0;
	
	return s;
} 

int full(Stack *p){
	return (p -> pointer == (MAX - 1));
}

int empty(Stack* p){
	/*
	 * return one (1) if the stack has no filled elements.
	 * return zero (0) if the stack has filled elements.
	 */
	return (p -> pointer == 0);
}

void push(Stack* p, float val){

	if(full(p) != 1){
		p -> value[p -> pointer] = val;
		p -> pointer ++;
	}
}

void list_all(Stack* p){
	
	int i = 0;
	while(i != (MAX - 1)){
		printf("Valor %2.f -- Na posição: %i\n", p -> value[i], i);
		i ++;
	}
}

void list_filled(Stack* p){
	
	int i = 0;
	while(i != (MAX - 1)){
		if(p -> value[i] != 0){
			printf("Valor %2.f -- Na posição: %i\n", p -> value[i], i);
		}
		i ++;
	}
}

void pop(Stack* p, int index){
	if (!empty(p))
	{
		p -> value[index] = 0;
	}
}

int main(){	
	Stack *s = new();
	
	push(s, 5);
	push(s, 7);
	push(s, 73);
	pop(s, 2);
	list_filled(s);
	return 0;
}




