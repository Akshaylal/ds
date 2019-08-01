#include<stdio.h>

int main(){
	int ar[20],i,j,n,s,found=0,temp;
	int f=0,l,m;
	printf("Enter array limit:");
	scanf("%d",&n);
	l=n;
	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	printf("Enter element to search:");
	scanf("%d",&s);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(ar[i]>ar[j]){
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
		}
	}
	m=(l+f)/2;
	for(i=0;i<n;i++){
		if(ar[m]==s){
			printf("Element found at %d\n",m);
			found=1;
			break;
		}else if(ar[m]<s){
			f=m;
			m=(f+l)/2;
		}else{
			l=m;
			m=(f+l)/2;
		}
	}
	if(!found){
		printf("Not found.\n");
	}
}
