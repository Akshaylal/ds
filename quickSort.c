#include<stdio.h>

int partition(int a[],int l, int h){
	int pivot=a[h];
	int i=l-1,j,t;
	for(j=l;j<h;++j){
		if(a[j]<=pivot){
			++i;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	++i;
	a[h]=a[i];
	a[i]=pivot;
	return i;
}

void quickSort(int a[],int l, int h){
	if(l<h){
		int p=partition(a,l,h);
		quickSort(a,l,p-1);
		quickSort(a,p+1,h);
	}
}

void main(){
	int ar[20],i,n;
	printf("Enter array limit:");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	quickSort(ar,0,n-1);
	printf("Sorted array:\n");
	for(i=0;i<n;i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
}
