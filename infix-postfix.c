#include <stdio.h>
#define STACK_MAX 100

char stack[STACK_MAX];
int top = -1;

void push(char key){
	if(STACK_MAX <= top){
		printf("Stack Overflow\n");
	}else{
		stack[++top] = key;	
	}
}

char pop(){
	if(top < 0){
		printf("Stack Underflow\n");
	}else{
		return stack[top--];
	}
}

int ISP(int inp){
	switch(inp){
		case '+':
		case '-':
			return 2;
			break;
		case '*':
		case '/':
			return 4;
			break;
		case '^':return 5;
			break;
		case '(':return 0;
			break;
	}
}

int ICP(char inp){
	switch(inp){
		case '+':
		case '-':
			return 1;
			break;
		case '*':
		case '/':
			return 3;
			break;
		case '^':return 6;
			break;
		case '(':return 9;
			break;
		case ')':return 0;
			break;
	}
}

void main(){
	char str[100], item, x;
	int i = -1, f = 1;
	push('(');
	
	while(top > -1){
		item = getchar();
		x = pop();
		if(item < 'z' & item > 'a'){
			push(x);
			str[++i] = item;
		}else if(item == ')'){
			while(x != '('){
				str[++i] = x;
				x = pop();
			}
		}else if(ISP(x) >= ICP(item)){
			while(ISP(x) >= ICP(item)){
				str[++i] = x;
				x = pop();
			}
			push(x);
			push(item);
		}else if(ISP(x) < ICP(item)){
			push(x);
			push(item);
		}else{
			f = 0;
			break;
		}
	}
	str[++i] = '\0';
	if(f){
		printf("%s\n",str);
	}else{
		printf("Invalid Expression");
	}
}
