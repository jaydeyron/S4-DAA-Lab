//headers and namespaces
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define intmax __INT_MAX__

//global variables
int **m,*temp;
int n;
char s=65;

//functions
int min(int a,int b){   return (a<b)?a:b;}
int max(int a,int b){   return (a>b)?a:b;}

int knap(int st)
{
	int visited=1,mincost=intmax;
	for(int i=0;i<n;i++){
		if(temp[i]==0){visited=0; break;}
	}
	if(visited){	return m[st][0];}
	for(int i=0;i<n;i++){
		if(temp[i]){continue;}
		temp[i]=1;
		int newcost=m[st][i]+ knap(i);
		temp[i]=0;
		mincost=min(newcost,mincost);
	}
	return mincost;
}

void getMat(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter (%d,%d) ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
}

void printMat(){
    printf("\n  ");
    for(int i=0;i<n;i++){
        printf("%c ",s);s++;
    }
    printf("\n");s=65;
    for(int i=0;i<n;i++){
        printf("%c ",s);s++;
        for(int j=0;j<n;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

//main
int main(){
    printf("Enter the no of cities:\t");scanf("%d",&n);
    m=malloc(n * sizeof(int *));
    temp=malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
            m[i]=malloc(n * sizeof(int));
            temp[i]=0;
    }
    getMat();
    printMat();
    int st=0;temp[st]=1;
    int mincost=knap(st);
    printf("Minimum cost:\t%d\n",mincost);
    return 0;
}
