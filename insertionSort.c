#include<stdio.h>

void main(){
	int i,j,k,ar[20],n,key;
	printf("Enter array limit:");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	
	for(i=1;i<n;i++){
		key=ar[i];
		for(j=i;j>-1;j--){
			if((key<ar[j-1])&&(j!=0)){
				ar[j]=ar[j-1];
				for(k=0;k<n;k++){
					printf("%d ",ar[k]);
				}
				printf("\n");
			}else{
				ar[j]=key;
				for(k=0;k<n;k++){
					printf("%d ",ar[k]);
				}
				printf("\n");
				break;
			}
		}
	}
	
	printf("Sorted array:\n");
	for(i=0;i<n;i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
}
