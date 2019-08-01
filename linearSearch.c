#include<stdio.h>

int main(){
	int ar[20],i,n,s,found=0;
	printf("Enter array limit:");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	printf("Enter element to search:");
	scanf("%d",&s);
	for(i=0;i<n;i++){
		if(ar[i]==s){
			printf("The element is at %d.\n",i);
			found=1;
			break;
		}
	}
	if(!found){
		printf("Not found.\n");
	}
}
