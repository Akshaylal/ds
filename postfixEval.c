#include <stdio.h>
#include <math.h>

#define STACK_MAX 100

float stack[STACK_MAX];
int top = -1;

void push(float key){
	if(STACK_MAX <= top){
		printf("Stack Overflow\n");
	}else{
		stack[++top] = key;	
	}
}

float pop(){
	if(top < 0){
		printf("Stack Underflow\n");
	}else{
		return stack[top--];
	}
}

void main(){
	char c;
	float x, y, t;
	
	printf("Enter postfix : ");
	
	while((c = getchar()) != '\n'){
		if((c >= '0') & (c <= '9')){
			push((float)(c-48));
		}else{
			y = pop();
			x = pop();
			switch(c){
				case '+':t = x + y;
				break;
				case '-':t = x - y;
				break;
				case '*':t = x * y;
				break;
				case '/':t = x / y;
				break;
				case '^':t = pow(x, y);
				break;
			}
			push(t);
		}
	}
	printf("%f\n", pop());
}
