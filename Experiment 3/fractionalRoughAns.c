#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void swap(double *a,double *b){
	double temp=*b;*b=*a;*a=temp;
}

void swapp(long *a,long *b){
	long temp=*b;*b=*a;*a=temp;
}

void bubblesort(double a[],long c[],long b[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);swapp(&c[j],&c[j+1]);swapp(&b[j],&b[j+1]);
			}
		}
	}
}


void printarr(long a[],long n){
	for(long i=0;i<n;i++){
		printf("%ld ",a[i]);
	}
	printf("\n");
}

void printarrd(double a[],long n){
	for(long i=0;i<n;i++){
		printf("%lf ",a[i]);
	}
	printf("\n");
}

void knapsack(long a[],long b[],double c[],long w,long n){
	double sumw=0,sump=0,temp;
	for(int i=n-1;i>-1;i--){
		if(sumw+b[i]<w){
			sumw+=b[i];
			sump+=a[i];
		}
		else{
			temp=a[i];
			temp/=b[i];
			temp*=(w-sumw);
			sump+=temp;
			break;
		}
	}
	printf("The maximum profit is:\t%lf\n",sump);
}
int main(){
	srand(time(0));
	clock_t b1,b2,q1,q2;
	double tot1,tot2;
	long n;
	printf("Enter size of array:\t");	scanf("%ld",&n);
	long a[n],b[n];
	double c[n];
	//printf("Enter array:\t");
	printf("Enter profits array:\n");
	for(int i=0;i<n;i++){
		//a[i]=rand()%(101);
		//b[i]=rand()%(10);
		//if(b[i]==0){b[i]++;}
		scanf("%ld",&a[i]);
	}
	printf("Enter weights array:\n");
	for(int i=0;i<n;i++){
		scanf("%ld",&b[i]);
		c[i]=(double)a[i]/(double)b[i];
	}
	//long w=rand()%100;
	long w;	scanf("%ld",&w);
	printf("Array of weights:\t");printarr(b,n);
	printf("Array of prices:\t");printarr(a,n);
	printf("Max weight:\t%ld\n",w);
	bubblesort(c,a,b,n);
	printarrd(c,n);
	knapsack(a,b,c,w,n);
}
