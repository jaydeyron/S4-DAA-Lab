#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printarr(int a[],int n){
	for(int i=0;i<n-1;i++){printf("%d  ",a[i]);}
	printf("\n");
}

void removearr(int a[],int d,int n){
	for(int i=d;i<n-1;i++){
		a[i]=a[i+1];
	}
}

void nextel(int temp,int n,int a[]){
	int mx=__INT_MAX__;
	for(int i=0;i<n-1;i++){
	if(a[i]>temp && a[i]<mx){mx=a[i];}
	}
	(mx==__INT_MAX__)?printf("%d was the largest number in the array\n",temp):printf("\nThe next largest number is:  %d\n",mx);
}

int main(){
	int n;
	printf("Enter the number of elements:\t");
	scanf("%d",&n);
	int a[n],x,pos;
	printf("Enter the elements:\t");
	for(int i=0;i<n;i++){scanf("%d",&x);a[i]=x;}
	printf("Enter the position of the element to remove:\t");
	scanf("%d",&pos);
	int temp=a[pos];
	if(pos>n-1){printf("Index out of bounds!");}
	else{removearr(a,pos,n);
	printf("Array after removal of element:   ");
	printarr(a,n);
	nextel(temp,n,a);}
	return 0;
}
