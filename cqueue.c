#include <stdio.h>
#define QUEUE_SIZE 5

int q[QUEUE_SIZE], front = -1, rear = -1, next;

void enq(int n){
	if(front == -1){
		front = rear = 0;
		q[rear] = n;
	}else{
		next = (rear + 1)%QUEUE_SIZE;
		if(next == front){
			printf("Queue is full\n");
		}else{
			rear = next;
			q[rear] = n;
		}
	}
}

void deq(){
	if(front == -1){
		printf("Queue is Empty\n");
	}else{
		printf("%d\n", q[front]);
		if(front == rear){	
			front = rear = -1;
		}else{
			front = (front + 1)%QUEUE_SIZE;
		}
	}
}

void status(){
	if(front == -1){
		printf("Queue is Empty\n");
	}else if((rear + 1)%QUEUE_SIZE == front){
		printf("Queue is full\n");
	}else{
		if(front == rear){
			printf("1 Element\n");
		}else if(front < rear){
			printf("%d elements\n", (rear-front+1));
		}else{
			printf("%d elements\n", (front+ QUEUE_SIZE-rear));
		}
	}
}



void main(){
	int c, n;
	do{
		printf("1. Enuqeue\n2. Dequeue\n3. Status\n0. Exit\n: ");
		scanf("%d", &c);
		switch(c){
			case 1:printf("Enter element:");
				scanf("%d", &n);
				enq(n);
			break;
			case 2:deq();
			break;
			case 3:status();
			break;
			case 0:;
			break;
			default:printf("Invalid\n");
		}
	}while(c != 0);
}
