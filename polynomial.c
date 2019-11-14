#include <stdio.h>
#include <stdlib.h>

struct poly{
	int exp, coe;
	struct poly *link;
}*pnew, *ptr2;

struct poly* getNode(){
	struct poly *p = malloc(sizeof(struct poly));
	p->link = NULL;
	return p;
}


void read_poly(struct poly **header){
	struct poly *ptr;
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
/*
struct poly* proper(struct poly *ptr){
	struct poly *max = ptr, *ptt, *oheader = NULL, *iheader = ptr;
	while(iheader != NULL){
		ptr = iheader->link;
		ptt = iheader;
		while(ptr != NULL){
			if(ptr->exp > max->exp){
				max = ptr;
				ptt = ptr;
			}
			ptr = ptr->link;
		}
		if(ptt->link == max & max->link != NULL){
			ptt->link = ptr->link;
			ptr->link = NULL;
		}
		if(oheader == NULL){
			oheader = max;
		}else{
			ptt = oheader;
			while(ptt->link != NULL){
				ptr = ptt;
				ptt = ptt->link;
			}
			ptr->link = max;
		}
		ptr = iheader;
		while(ptr != NULL){
			while((ptr != NULL) & (ptr->exp != max->exp)){
				ptt = ptr;
				ptr = ptr->link;
			}
			if(ptr != NULL){
				if(ptr->exp == max->exp){
					max->coe += ptr->coe;
					ptt->link = ptr->link;
					free(ptr);
				}
			}
		}
	}
	return oheader;
}
*/
struct poly* padd(struct poly *pptr, struct poly *qptr){
	struct poly *h = getNode(), *rptr;
	rptr = h;
	while((pptr != NULL) & (qptr != NULL)){
		rptr->link = getNode();
		rptr = rptr->link;
		if(pptr->exp == qptr->exp){
			rptr->exp = pptr->exp;
			rptr->coe = pptr->coe + qptr->coe;
			pptr = pptr->link;
			qptr = qptr->link;
		}else if(pptr->exp > qptr->exp){
			rptr->exp = pptr->exp;
			rptr->coe = pptr->coe;
			pptr = pptr->link;
		}else{
			rptr->exp = qptr->exp;
			rptr->coe = qptr->coe;
			qptr = qptr->link;
		}
	}
	if(pptr != NULL){
		while(pptr != NULL){
			rptr->link = getNode();
			rptr = rptr->link;
			rptr->exp = pptr->exp;
			rptr->coe = pptr->coe;
			pptr = pptr->link;
		}
	}
	if(qptr != NULL){
		while(qptr != NULL){
			rptr->link = getNode();
			rptr = rptr->link;
			rptr->exp = qptr->exp;
			rptr->coe = qptr->coe;
			qptr = qptr->link;
		}
	}
	return h->link;
}

struct poly* pmul(struct poly *pptr, struct poly *qptr){
	struct poly *h = getNode(), *rptr, *rptr1, *qptrc;
	int coe, exp;
	rptr = h;
	if((pptr == NULL) | (qptr == NULL)){
		printf("Cannot perform multiplication\n");	
	}else{
		while(pptr != NULL){
			qptrc = qptr;
			while(qptrc != NULL){
				rptr->link = getNode();
				rptr = rptr->link;
				rptr->coe = pptr->coe * qptrc->coe;
				rptr->exp = pptr->exp + qptrc->exp;
				qptrc = qptrc->link;
			}
			pptr = pptr->link;
		}
	}
	return h->link;
}

void display(struct poly *ptr){
	struct poly *p = ptr;
	while(ptr != NULL){
		if(ptr->coe != 0){
			if(ptr->coe < 0){
				printf("%d", ptr->coe);
			}else{
				printf("+%d", ptr->coe);
			}	
			printf("x^%d", ptr->exp);
		}
		ptr = ptr->link;
	}
}



void main(){
	struct poly *p1, *p2, *p3;
	printf("First polynomial:\n");
	read_poly(&p1);
	printf("Second polynomial:\n");
	read_poly(&p2);
	display(p1);
	printf("\n");
	display(p2);
	printf("\n");
	p3 = pmul(p1, p2);
	display(p3);
	printf("\n");
}