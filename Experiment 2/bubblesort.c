#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
	int temp=*b;*b=*a;*a=temp;
}

void bubblesort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
}

void printarr(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter size of array:\t");	scanf("%d",&n);
	int a[n];
	printf("Enter array:\t");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Before sort:\t"); printarr(a,n);
	bubblesort(a,n);
	printf("After sort:\t"); printarr(a,n);
	return 0;
}
