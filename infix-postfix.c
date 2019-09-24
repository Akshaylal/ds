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

int ISP(){
	int y;
	char x = pop();
	switch(x){
		case '(':y = 0;
		break;
		case '+':
		case '-':y = 2;
		break;
		case '*':
		case '/':
		case '%':y = 4;
		break;
		case '^':y = 5;
		break;
	}
	push(x);
	return y;
}

int ICP(char inp){
	switch(inp){
		case '(':return 100;
		break;
		case '+':
		case '-':return 1;
		break;
		case '*':
		case '/':
		case '%':return 3;
		break;
		case '^':return 6;
		break;
	}
}

void main(){
	char str[100], c, ch;
	int i = -1;
	push('(');
	while((c = getchar()) != '\n'){
		if((c>'A' & c<'Z') | (c>'a' &c<'z')){
			str[++i] = c;
		}else if(c == ')'){
			while((ch = pop()) != '('){
				str[++i] = ch;
			}
		}else{
			if(ICP(c) > ISP()){
				push(c);
			}else{
				while(ISP() >= ICP(c)){
					str[++i] = pop();
				}
			}
		}
	}
	str[++i] = '\0';
	printf("%s\n",str);
}
