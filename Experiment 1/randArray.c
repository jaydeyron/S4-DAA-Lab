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
 	srand(time(0));
 	clock_t d1,d2,l1,l2;
 	double tot1,tot2;
	long n;
	printf("Enter the number of elements:\t");
	scanf("%ld",&n);
	int a[n],x,pos,t;
	for(int i=0;i<n;i++){
		a[i]=rand()%(101);
	}
	pos=rand()%(n);
	int temp=a[pos];
	//printf("Array before:\t");printarr(a,n);
	//printf("Element to be deleted:\t%d\n",temp);
	d1=clock();
	removearr(a,pos,n);
	d2=clock();
	tot1=((double)d2-d1)/CLOCKS_PER_SEC;
	//printf("Array after:\t");printarr(a,n-1);
	l1=clock();
	nextel(temp,n,a);
	l2=clock();
	tot2=((double)l2-l1)/CLOCKS_PER_SEC;
	printf("Time taken for deletion:\t%.9lf\n",tot1);
	printf("Time taken for finding next element:\t%.9lf\n",tot2);
	return 0;
}
