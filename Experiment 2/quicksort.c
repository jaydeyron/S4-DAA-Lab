#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x,int *y){
    int temp=*x;*x=*y;*y=temp;
}

int partition(int a[],int low,int high){
    int piv=a[high];
    int i=(low-1);
    for(int j=low;j<high;j++){
        if(a[j]<=piv){  i++;swap(&a[i],&a[j]);}
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}

void quicksort(int a[],int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}

void printarr(int *a,int *n){
    for(int i=0;i<*n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
  int n;
  scanf("%d",&n);
  int a[n];for(int i=0;i<n;i++){scanf("%d",&a[i]);}
  printf("\nBefore sort:\t");
  printarr(a,&n);
  quicksort(a,0,n-1);
  printf("After sort:\t");
  printarr(a,&n);
  return 0;
}
