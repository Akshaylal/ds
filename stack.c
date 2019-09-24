#include <stdio.h>
#define STACK_MAX 100

void push(int s[], int *top, int key){
	if(STACK_MAX <= *top){
		printf("Stack Overflow\n");
	}else{
		s[++(*top)] = key;	
	}
}

int pop(int s[], int *top){
	if((*top) < 0){
		printf("Stack Underflow\n");
		return NULL;
	}else{
		return s[(*top)--];
	}
}

void status(int s[],int *top){
	if(*top == STACK_MAX){
		printf("Stack Full\n");
	}else if(*top == -1){
		printf("Stack Empty\n");
	}else{
		printf("Stack is at %d\n", *top);
	}
}

void main(){
	int stack[STACK_MAX], top = -1, opt, t = 1, key;
	while(t){
		printf("1. PUSH\n2. POP\n3. Status\n4. Exit\n:");
		scanf("%d",&opt);
		switch(opt){
			case 1:printf("Enter element:");
				scanf("%d",&key);
				push(stack,&top,key);
				break;
			case 2:key = pop(stack,&top);
				if(key!=NULL){
					printf("%d\n", key);
				}
				break;
			case 3:status(stack, &top);
				break;
			case 4:t = 0;
				break;
			default:printf("Invalid\n");
		}
	}
}
