//headers and namespaces
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define intmax __INT_MAX__

//global variables                      // Not fully dynamic, uses iteration and no memoization, path may not be correct for bigger graphs
int **m,*temp,*path,*pt;                // Also works only for complete graphs and not for incomplete graphs
int n;    
int rec=0,flag=0,it=0,visited;
//int m[5][5]={{0,2,0,12,5},{2,0,4,8,0},{0,4,0,3,3},{12,8,3,0,10},{5,0,3,10,0}}; 
//int m[4][4]={{0,10,15,20},{5,0,9,10},{6,13,0,12},{8,8,9,0}};                             
char s=65;

//functions
int min(int a,int b){   return (a<b)?a:b;}
int max(int a,int b){   return (a>b)?a:b;}

void copy(int a[],int b[],int n){
    for(int i=1;i<n;i++){a[i]=b[i];}
}

int tsp(int st)
{
	visited=1;
    int mincost=intmax;
	for(int i=1;i<n;i++){
		if(temp[i]==0){visited=0; break;}
	}
	if(visited){
        path[rec+1]=st;
		return m[st][0];
	}
	for(int i=0;i<n;i++){
		if(temp[i]){continue;}
        if(m[st][i]==0){break;}
		temp[i]=1;
        rec++;
        pt[rec]=i;
		int newcost=m[st][i]+ tsp(i);
        rec--;
		temp[i]=0;
        if(visited==1 && rec==0 && newcost<mincost){copy(path,pt,n);}
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
    path[n]=1;
    printf("%d-->",path[0]);
    for (int i = 1; i < n; i++) {
        printf("%d", path[i]+1);
        if(i<n){printf("-->");}
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
    pt=malloc(n+1 * sizeof(int *));
    temp=malloc((n+1) * sizeof(int));
    for(int i=0;i<n;i++){
            m[i]=malloc(n * sizeof(int));
            temp[i]=0;
            pt[i]=0;
    }
    getMat();
    printMat();
    int st=0;temp[st]=1;path[n]=1,path[0]=1;
    int mincost=tsp(st);
    printf("Minimum cost:\t%d\n",mincost);
    printPath();
    return 0;
}
