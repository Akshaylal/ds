#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
}*ptr, *ptr2, *pnew, *header = NULL;

void insert_begin(int dat){
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

void insert_end(int dat){
	pnew = malloc(sizeof(struct node));
	if(pnew == NULL){
		printf("No memory, element not added\n");
	}else{
		pnew->data = dat;
		if(header == NULL){
			pnew->link = NULL;
			header = pnew;
		}else{
			ptr = header;
			while(ptr->link != NULL){
				ptr = ptr->link;
			}
			pnew->link = NULL;
			ptr->link = pnew;
		}
	}
}

void delete_begin(){
	ptr = header;
	header = header->link;
	free(ptr);
}

void delete_end(){
	ptr = header;
	while(ptr->link != NULL){
		ptr2 = ptr;
		ptr = ptr->link;
	}
	free(ptr);
	ptr2->link = NULL;
}

void main(){
	int c, n;
	do{
		printf("1. Insert Begin\n2. Insert End\n3. Insert key\n4. Delete Begin\n5. Delete End\n6. Delete key\n7. Display\n0. Exit\n: ");
		scanf("%d", &c);
		switch(c){
			case 1:
				printf("Enter element : ");
				scanf("%d", &n);
				insert_begin(n);
			break;
			case 2:
				printf("Enter element : ");
				scanf("%d", &n);
				insert_end(n);
			break;
			case 3:
			break;
			case 4:delete_begin();
			break;
			case 5:delete_end();
			break;
			case 6:
			break;
			case 7:
			break;
			default:printf("Invalid\n");
		}
	}while(c != 0);
}
