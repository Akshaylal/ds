#include<stdio.h>
#define HEAP_SIZE 100

void createHeap(int b[], int a[], int n){
	int i, j, temp;
	for(i=0; i<n; ++i){
		b[i] = a[i];
		j = i;
		while(j>0){
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

void main(){
	int a[HEAP_SIZE], n, b[HEAP_SIZE], i;
	printf("Enter array limit: ");
	scanf("%d", &n);
	printf("Enter elements: ");
	for(i=0; i<n; ++i)
		scanf("%d", &a[i]);
	printf("Array : \n");
	for(i=0; i<n; ++i)
		printf("%d\t", a[i]);
	printf("\n");
	createHeap(b,a,n);
	printf("After Max Heap \n");
	for(i=0; i<n; ++i)
		printf("%d\t", b[i]);
	printf("\n");	
}
