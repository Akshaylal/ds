#include <stdio.h>
#define STACK_MAX 100

int s[STACK_MAX], TopA = -1, TopB = STACK_MAX;


/////Stack A
void pushA(int key){
	if((TopA + 1) == TopB){
		printf("Stack Overflow\n");
	}else{
		s[++TopA] = key;	
	}
}

void popA(){
	if(TopA < 0){
		printf("Stack Underflow\n");
	}else{
		printf("%d\n", s[TopA--]);
	}
}

void statusA(){
	if((TopA + 1) == TopB){
		printf("Stack Full\n");
	}else if(TopA < 0){
		printf("Stack Empty\n");
	}else{
		printf("%d elements in Stack A\n", (TopA + 1));
	}
}

/////Stack B

void pushB(int key){
	if((TopB - 1) == TopA){
		printf("Stack Overflow\n");
	}else{
		s[--TopB] = key;	
	}
}

void popB(){
	if(TopB == STACK_MAX){
		printf("Stack Underflow\n");
	}else{
		printf("%d\n", s[TopB++]);
	}
}

void statusB(){
	if((TopB - 1) == TopA){
		printf("Stack Full\n");
	}else if(TopB == STACK_MAX){
		printf("Stack Empty\n");
	}else{
		printf("%d elements in Stack B\n", (STACK_MAX - TopB));
	}
}
/////////////////////////////////////////////////
void main(){
	int opt, key;
	do{
		printf("1. PushA\n2. PopA\n3. StatusA\n4. PushA\n5. PopA\n6. StatusA\n0. Exit\n:");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Enter element : ");
				scanf("%d", &key);
				pushA(key);
			break;
			case 2:popA();
			break;
			case 3:statusA();
			break;
			case 4:
				printf("Enter element : ");
				scanf("%d", &key);
				pushB(key);
			break;
			case 5:popB();
			break;
			case 6:statusB();
			break;
			case 0:;
			break;
			default:printf("Invalid choice\n");
		}
	}while(opt != 0);
}
