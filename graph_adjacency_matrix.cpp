#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
        int v,e;
        int **a;
        graph(int a,int b){
            v=a;
            e=b;
        }
        void addedge(int v1,int v2){
            a[v1][v2]=1;
            a[v2][v1]=1;
        }
};
int main(){
    graph g1(4,3);
    int i,j,a,b;
    cout<<"enter number of vertices:- ";
    cin>>g1.v;
    g1.a=new int* [g1.v];
    cout<<"enter number of edges:- ";
    cin>>g1.e;
    for(i=0;i<g1.v;i++){
        g1.a[i]=new int [g1.v];
        for(j=0;j<g1.v;j++){
            g1.a[i][j]=0;
        }
    }
    cout<<"enter vertices which has edge between them:-  ";
    for(i=0;i<g1.e;i++){
        cin>>a>>b;
        g1.addedge(a,b);
    }
    for(i=0;i<g1.v;i++){
        for(j=0;j<g1.v;j++){
            cout<<g1.a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}