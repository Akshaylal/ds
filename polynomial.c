#include <stdio.h>
#include <stdlib.h>

struct poly{
	int exp, coe;
	struct poly *link;
}*ptr2;

struct poly* getNode(){
	struct poly *p = malloc(sizeof(struct poly));
	p->link = NULL;
	return p;
}


struct poly* search(struct poly *header, int key){
	if(header == NULL){
		return NULL;
	}else{
		struct poly *ptr = header;
		while((ptr->link != NULL) & (ptr->exp != key)){
			ptr2 = ptr;
			ptr = ptr->link;
		}
		if(ptr->exp != key){
			return NULL;
		}else{
			return ptr2;
		}
	}
}


void read_poly(struct poly **header){
	struct poly *pnew, *ptr;
	int n, i;
	*header = NULL;
	printf("Enter number of terms:");
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		pnew = getNode();
		printf("Enter Exponent:");
		scanf("%d", &pnew->exp);
		printf("Enter Coefficient:");
		scanf("%d", &pnew->coe);
		if(*header == NULL){
			*header = pnew;
		}else{
			ptr->link = pnew;
		}
		ptr = pnew;
	}	
}

void display(struct poly **header){
	struct poly *ptr = *header;
	while(ptr != NULL){
		printf("%dx^%d+", ptr->coe, ptr->exp);
		ptr = ptr->link; 
	}
}

int keys[25], key = -1;
void add_ex(int n){
	keys[++key] = n;
}
int s_key(int n){
	int i;
	for(i = 0; i <= key; ++i){
		if(keys[i] == n)
			return 1;
		else
			return 0;
	}
}
void cl_key(){
	key = -1;
}

void padd(struct poly *pt1, struct poly *pt2, struct poly **pt3){
	*pt3 = NULL;
	struct poly *temp, *ptrt;
	while(pt1 != NULL){
		ptrt = getNode();
		if(*pt3 == NULL){
			*pt3 = ptrt;
		}
		temp = search(pt2, pt1->exp);
		ptrt->exp = pt1->exp;
		if(temp == NULL){
			ptrt->coe = pt1->coe;
			pt1 = pt1->link;
		}else{
			add_ex(pt1->exp);
			ptrt->coe = pt1->coe + pt2->coe;
			pt1 = pt1->link;
			pt2 = pt2->link;
		}
	}
	while(pt2 != NULL){
		ptrt = getNode();
		if(*pt3 == NULL){
			*pt3 = ptrt;
		}
		if(s_key(pt2->exp) != 1){
			ptrt->exp = pt1->exp;
		}
		ptrt->exp = pt2->exp;
		ptrt->coe = pt2->coe;
	}
	cl_key();
}

void main(){
	struct poly *p1, *p2, *p3;
	printf("First polynomial:\n");
	read_poly(&p1);
	printf("Second polynomial:\n");
	read_poly(&p2);
	padd(p1, p2, &p3);
	display(&p3);
	printf("\n");
}
