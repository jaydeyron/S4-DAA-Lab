//headers and namespaces
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iterator>
#define intmax __INT_MAX__
using namespace std;

//global variables
int n;
vector<int> path;
vector<vector<int> >mat;  vector<vector<int> > memo;

//functions
void insertMat(vector<vector<int> > memo){
    int a;
    for(int i=0;i<n;i++){
        vector<int> vec0;  memo.push_back(vec0);  mat.push_back(vec0);
        path.push_back(0);
        for(int j=0;j<n;j++){
            cin>>a; memo[i].push_back(-1);
            mat[i].push_back(a);
        }
    }
}

void printMat(){
    char s=65;  cout<<"\n ";
    for(int i=0;i<n;i++){
        cout<<' '<<s;   s++;
    }
    cout<<"\n\n";   s=65;
    for(int i=0;i<n;i++){
        cout<<s;    s++;
        for(int j=0;j<n;j++){
            cout<<' '<<mat[i][j];
        }   printf("\n\n");
    }
}

int tsp(int i, vector<int> temp){
    int res=intmax;
    if(temp.size()==0 && i!=0){
        return mat[i][0];
    }
    for(int j=0;j<temp.size();j++){
        //if(i==j){continue;}
        int tp=temp[j];
        temp.erase(temp.begin()+j);
        //res=min(res, mat[i][j]+tsp(i,vector<int> (temp)));
        int mn=mat[i][tp]+tsp(tp,vector<int>(temp));
        if(mn<res){
            res=mn; path[i]=tp;
        }
        //cout<<res<<' ';
        temp.insert(temp.begin()+j,tp);
    }
    return res;
}

void printPath(){
    cout<<"\nPath:\t1";
    for(int i=0;i<n;i++){
        cout<<"-->"<<path[i]+1;
    }
}
//main
int main(){
    cout<<"Enter the number of cities:\t"; cin>>n;
    vector<int> temp;
    for(int i=1;i<n;i++){temp.push_back(i);}
    insertMat(memo);
    printMat();
    //cout<<(temp.size())<<'\n';
    int mincost=tsp(0,temp);
    cout<<"Minimum cost:\t"<<mincost;
    //printPath();
    return 0;
}
