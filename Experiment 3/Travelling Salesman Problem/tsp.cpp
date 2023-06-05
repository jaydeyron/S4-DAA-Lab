//headers and namespaces
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iterator>

using namespace std;

//global variables
int n;
vector<vector<int> >mat;

//functions
void insertMat(){
    int a;
    for(int i=0;i<n;i++){
        vector<int> vec1;   mat.push_back(vec1);
        for(int j=0;j<n;j++){
            cin>>a; mat[i].push_back(a);
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
        }
        printf("\n\n");
    }
}

//main
int main(){
    cout<<"Enter the number of cities:\t"; cin>>n;
    insertMat();
    printMat();
    return 0;
}
