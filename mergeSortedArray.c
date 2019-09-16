#include<stdio.h>

void main(){
	int a1[20],a2[20],b[40];
	int i,j,temp,k,n1,n2;
	
	printf("Enter array limit (1):");
	scanf("%d",&n1);
	printf("Enter elements:\n");
	for(i=0;i<n1;i++){
		scanf("%d",&a1[i]);
	}
	printf("Enter array limit (2):");
	scanf("%d",&n2);
	printf("Enter elements:\n");
	for(i=0;i<n2;i++){
		scanf("%d",&a2[i]);
	}
	
	for(i=0;i<n1-1;i++){
		for(j=i+1;j<n1;j++){
			if(a1[i]>a1[j]){
				temp=a1[i];
				a1[i]=a1[j];
				a1[j]=temp;
			}
		}
	}
	for(i=0;i<n2-1;i++){
		for(j=i+1;j<n2;j++){
			if(a2[i]>a2[j]){
				temp=a2[i];
				a2[i]=a2[j];
				a2[j]=temp;
			}
		}
	}
	
	i=0;j=0;
	for(k=0;k<(n1+n2);k++){
		if(i==n1){
			b[k]=a2[j];
			j++;
			continue;
		}else if(j==n2){
			b[k]=a1[i];
			i++;
			continue;
		}
		if(a1[i]<a2[j]){
			b[k]=a1[i];
			i++;
		}else{
			b[k]=a2[j];
			j++;
		}
	}
	printf("\nMerged Array:\n");
	for(i=0;i<(n1+n2);i++){
		printf("%d ",b[i]);
	}
	printf("\n");
}
