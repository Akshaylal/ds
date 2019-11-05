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
		printf("Data inserted\n");
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
		printf("Data inserted\n");
	}
}

void insert_key(int key, int data){
	if(header == NULL){
		printf("List Empty. Inserting at begining\n");
		insert_begin(data);
	}else{
		ptr = header;
		while((ptr->link != NULL) & (ptr->data != key)){
			ptr = ptr->link;
		}
		if(ptr->link == NULL){
			printf("Key not found. Inserting at End\n");
			insert_end(data);
		}else{
			pnew = malloc(sizeof(struct node));
			pnew->data = data;
			pnew->link = ptr->link;
			ptr->link = pnew;
			printf("Inserted after %d\n", data);
		}
	}
}

void delete_begin(){
	if(header == NULL){
		printf("List Empty\n");
	}else{
		ptr = header;
		header = header->link;
		free(ptr);
		printf("Deleted\n");
	}
}

void delete_end(){
	if(header == NULL){
		printf("List Empty\n");
	}else{
		ptr = header;
		while(ptr->link != NULL){
			ptr2 = ptr;
			ptr = ptr->link;
		}
		if(header == ptr){
			header = NULL;
		}else{
			ptr2->link = NULL;
		}
		free(ptr);
		printf("Deleted\n");
	}
}

void delete_key(int key){
	if(header == NULL){
		printf("List Empty\n");
	}else{
		ptr = header;
		while((ptr->link != NULL) & (ptr->data != key)){
			ptr2 = ptr;
			ptr = ptr->link;
		}
		if(ptr->data != key){
			printf("Not found\n");
		}else{
			if(header == ptr){
				header = NULL;
			}else{
				ptr2->link = ptr->link;
			}
			free(ptr);
			printf("%d Deleted\n", key);
		}
	}
}

void display(){
	ptr = header;
	if(header == NULL){
		printf("List Empty\n");
	}
	while(ptr != NULL){
		printf("%d\t%p\n", ptr->data, ptr->link);
		ptr = ptr->link; 
	}
}

void main(){
	int c, n, key;
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
				printf("Enter key : ");
				scanf("%d", &key);
				printf("Enter element : ");
				scanf("%d", &n);
				insert_key(key, n);
			break;
			case 4:delete_begin();
			break;
			case 5:delete_end();
			break;
			case 6:
				printf("Enter key : ");
				scanf("%d", &key);
				delete_key(key);
			break;
			case 7:display();
			break;
			case 0:;
			break;
			default:printf("Invalid\n");
		}
	}while(c != 0);
}
