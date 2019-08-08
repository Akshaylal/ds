#include<stdio.h>

void main(){
	int i,j,ar[20],n,temp;
	printf("Enter array limit:");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(ar[i]>ar[j]){
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
		}
	}
	printf("Sorted array:\n");
	for(i=0;i<n;i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
}
