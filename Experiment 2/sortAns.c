#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void swap(long *a,long *b){
	long temp=*b;*b=*a;*a=temp;
}

void bubblesort(long a[],long n){
	for(long i=0;i<n-1;i++){
		for(long j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
}

int partition(long a[],long low,long high){
    long piv=a[high/2];
    long i=(low-1);
    for(long j=low;j<high;j++){
        if(a[j]<=piv){  i++;swap(&a[i],&a[j]);}
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}

void quicksort(long a[],long low,long high){
    if(low<high){
        long pi=partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}

void printarr(long a[],long n){
	for(long i=0;i<n;i++){
		printf("%ld ",a[i]);
	}
	printf("\n");
}

int main(){
	srand(time(0));
	clock_t b1,b2,q1,q2;
	double tot1,tot2;
	long n;
	printf("Enter size of array:\t");	scanf("%ld",&n);
	long a[n],b[n];
	//printf("Enter array:\t");
	for(int i=0;i<n;i++){
		a[i]=rand()%(1001);
		b[i]=a[i];
		//scanf("%d",&a[i]);
		//b[i]=a[i];
	}
	//printf("Before  sort:\t"); printarr(a,n);
	b1=clock();
	bubblesort(a,n);
	b2=clock();
	tot1=((double)b2-b1)/CLOCKS_PER_SEC;
 	printf("\nTime taken for bubble sort:\t%lf\n",tot1);
	//printf("After bubble sort:\t"); printarr(a,n);
	q1=clock();
  	quicksort(b,0,n-1);
  	q2=clock();
  	tot2=((double)q2-q1)/CLOCKS_PER_SEC;
 	//printf("After quick sort:\t");	printarr(b,n);
 	printf("\nTime taken for quick sort:\t%lf\n",tot2);
 	FILE *fp;
 	fp=fopen("/home/student/fl.dat","a");
 	fprintf(fp,"%ld\t%lf\t%lf\n",n,tot1,tot2);
 	//fprintf(fp,"%.10lf\n",tot2);
 	fclose(fp);

	return 0;
}
