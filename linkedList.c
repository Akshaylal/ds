#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
}*ptr, *pnew, *header = NULL;

void push(int dat){
	pnew = malloc(sizeof(struct node));
	if(pnew == NULL){
		printf("No memory, element not added\n");
	}else{
		pnew->data = dat;
		if(header == NULL){
			pnew->link = NULL;
			header = pnew;
		}else{
			pnew->link = header;
			header = pnew;
		}
	}
}

int pop(){
	int dat = header->data;
	ptr = header;
	header = header->link;
	free(ptr);
	return dat;
}

void status(){
	int count = 0;
	ptr = header;
	while(ptr != NULL){
		ptr = ptr->link;
		count++;
	}
	if(count == 0){
		printf("Stack is empty\n");
	}else{
		printf("%d Elements in Stack\n", count);
	}
}

void pops(){
	if(header == NULL){
		printf("Stack Underflow\n");
	}else{
		printf("%d\n", pop());
	}
}

void main(){
	int c, n;
	do{
		printf("1. PUSH\n2. POP\n3. STATUS\n0. Exit\n: ");
		scanf("%d", &c);
		switch(c){
			case 1:
				printf("Enter element: ");
				scanf("%d", &n);
				push(n);
			break;
			case 2:pops();
			break;
			case 3:
				status();
			break;
			default:printf("Invalid\n");
		}
	}while(c != 0);
}
