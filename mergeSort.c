#include<stdio.h>

void merge(int a[], int l, int m, int h){
	int t[20],i=l,j=m+1,k=l;
	while(i<=m && j<=h){
		if(a[i]<a[j]){
			t[k]=a[i];
			++i;
		}else{
			t[k]=a[j];
			++j;
		}
		++k;
	}
	while(i<=m){
		t[k]=a[i];
		++i;
		++k;
	}
	while(j<=h){
		t[k]=a[j];
		++j;
		++k;
	}
	for(i=l;i<=h;++i){
		a[i]=t[i];
	}
}

void mergeSort(int a[], int l, int h){
	if(l<h){
		int mid=(l+h)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,h);
		merge(a,l,mid,h);
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
	mergeSort(ar,0,n-1);
	printf("Sorted array:\n");
	for(i=0;i<n;i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
}
