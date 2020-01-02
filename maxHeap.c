#include<stdio.h>
#define HEAP_SIZE 100

int n = -1, heap[HEAP_SIZE];

void maxHeap(int x){
	int i, p, temp;
	if(n>HEAP_SIZE){
		printf("Heap Full\n");
	}else{
		heap[++n] = x;
		i = n;
		p = i / 2;
		while(p >= 0 & heap[p] < heap[i]){
			temp = heap[p];
			heap[p] = heap[i];
			heap[i] = temp;
			i = p;
			p = i / 2;
		}
	}
}

void main(){
	int c, key, i;
	do{
		printf("key : ");
		scanf("%d", &key);
		maxHeap(key);
		printf("more?(1/0) : ");
		scanf("%d", &c);
	}while(c != 0);
	for(i = 0; i <= n; ++i){
		printf("%d ", heap[i]);
	}
	printf("\n");
}
