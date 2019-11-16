#include<stdio.h>
#define SIZE 100
#define root 0

void swap(int *pn1,int *pn2){
	int temp;
	temp = *pn1;
	*pn1 = *pn2;
	*pn2 = temp;
}

void printArray(int b[], int i){
	int j;
	for(j=0; j<i; ++j)
		printf("%d\t", b[j]);
	printf("\n");
}

void createHeap(int a[], int b[], int n){
	int i, j, temp;
	for(i=0; i<n; ++i){
		b[i] = a[i];	
		j = i;			
		while(j>root){	
			if(b[j]>b[(j-1)/2]){
				temp = b[j];
				b[j] = b[(j-1)/2];
				b[(j-1)/2] = temp;
				j = (j-1)/2;
			}
			else
				j=0;
		}
	}	
}

void removeMax(int b[], int i){
	int temp;
	temp = b[i];
	b[i] = b[root];
	b[root] = temp;
}

void rebuildHeap(int b[], int i){
	int j, flag, lc, rc;
	if(i==root)
		return;
	j = 0;
	flag = 1;
	while(1 == flag){
		lc = 2*j+1;
		rc = 2*j+2;
		if(rc <= i){
			if(b[j] < b[lc] && b[lc] >= b[rc]){
				swap(&b[j], &b[lc]);
				j = lc;	
			}
			else if(b[j] < b[rc] && b[rc] >= b[lc]){
				swap(&b[j], &b[rc]);
				j = rc;	
			}
			else
				flag = 0;
		}
		else{
			if(lc <= i){
				if(b[j] <= b[lc]);
				swap(&b[j], &b[lc]);
				j = lc;	
			}
			else
				flag = 0;
		}
	}
}

void heapSort(int a[], int b[], int n){
	int j;
	createHeap(a,b,n);
	printf("After max heap : \n");
	printArray(b, n);
	for(j=n-1; j>0; --j){
		removeMax(b, j);
		rebuildHeap(b, j-1);
	}
}

void main(){
	int a[SIZE], n, b[SIZE], i;
	printf("Enter the array limit: ");
	scanf("%d", &n);
	printf("Enter elements: ");
	for(i=0; i<n; ++i)
		scanf("%d", &a[i]);
	printf("array : \n");
	for(i=0; i<n; ++i)
		printf("%d\t", a[i]);
	printf("\n");
	heapSort(a, b, n);
	printf("After heap sort :\n");
	printArray(b, n);
}
