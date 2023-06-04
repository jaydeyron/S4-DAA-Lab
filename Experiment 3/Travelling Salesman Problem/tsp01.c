//headers and namespaces
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define intmax __INT_MAX__

//global variables                      // Not fully dynamic, uses iteration
int **m,*temp,*path;                    // Also works only for complete graphs and not for incomplete graphs
int n;                                  
char s=65;

//functions
int min(int a,int b){   return (a<b)?a:b;}
int max(int a,int b){   return (a>b)?a:b;}

int tsp(int st)
{
	int visited=1,mincost=intmax;
	for(int i=0;i<n;i++){
		if(temp[i]==0){visited=0; break;}
	}
	if(visited){
		return m[st][0];
	}
	for(int i=0;i<n;i++){
		if(temp[i]){continue;}
		temp[i]=1;
		int newcost=m[st][i]+ tsp(i);
		temp[i]=0;
		mincost=min(newcost,mincost);
	}
	return mincost;
}

void getMat(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter [%d,%d] ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
}

void printPath(){
    printf("Path: ");
    path[n-1]=1;
    for (int i = 0; i < n; i++) {
        printf("%d-->", path[i]);
    }
    printf("%d\n\n",path[n]);
}

void printMat(){
    printf("\n  ");
    for(int i=0;i<n;i++){
        printf(" %c ",s);s++;
    }
    printf("\n\n");s=65;
    for(int i=0;i<n;i++){
        printf("%c  ",s);s++;
        for(int j=0;j<n;j++){
            printf("%d  ",m[i][j]);
        }
        printf("\n\n");
    }
}

//main
int main(){
    printf("Enter the no of cities:\t");scanf("%d",&n);
    m=malloc(n * sizeof(int *));
    path=malloc(n+1 * sizeof(int *));
    temp=malloc((n+1) * sizeof(int));
    for(int i=0;i<n;i++){
            m[i]=malloc(n * sizeof(int));
            temp[i]=0;
    }
    getMat();
    printMat();
    int st=0;temp[st]=1;path[n]=1;
    int mincost=tsp(st);
    printf("Minimum cost:\t%d\n",mincost);
    //printPath();
    return 0;
}
