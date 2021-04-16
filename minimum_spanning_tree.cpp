///Prim's algorithm for minimum spanning tree
#include<bits/stdc++.h>
using namespace std;

int findmin(int* weight,bool* visited,int n){
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex==-1 || weight[i] < weight[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}

class graph{
    public:
        int v;
        int e;
        int** adj;
        void addedges(){
            cout<<"Enter vertices which has edge between them and then weight of edge";
            int i,a,b,w;
            for(i=0;i<this->e;i++){
                cin>>a>>b>>w;
                this->adj[a][b]=w;
                this->adj[b][a]=w;
            }
        }
        graph(int a,int b){
            this->v=a;
            this->e=b;
            this->adj=new int* [a];
            int i,j;
            for(i=0;i<a;i++){
                this->adj[i]=new int[a];
                for(j=0;j<a;j++){
                    this->adj[i][j]=0;
                }
            }
        }
        ~graph(){
            int i;
            for(i=0;i<this->v;i++){
                delete [] adj[i];
            }
        }
        void prims(){
            int n=this->v;
            int* parent=new int [n];
            int* weight=new int [n];
            bool* visited=new bool[n];
            for(int i=0;i<n;i++){
                visited[i]=false;
                weight[i]=INT_MAX;
            }
            parent[0]=-1;
            weight[0]=0;
            for(int i=0;i<n;i++){
                int minvertex=findmin(weight,visited,n);
                visited[minvertex]=true;
                for(int j=0;j<n;j++){
                    if(this->adj[minvertex][j]!=0 && !visited[j]){
                        if(this->adj[minvertex][j]<weight[j]){
                            weight[j]=this->adj[minvertex][j];
                            parent[j]=minvertex;
                        }
                    }
                }
            }
            cout<<"Edge1    Edge2   Weight"<<endl;
            for(int i=1;i<n;i++){
                if(parent[i]<i){
                    cout<<parent[i]<<"      "<<i;
                }
                else{
                    cout<<i<<"      "<<parent[i];
                }
                cout<<"     "<<weight[i]<<endl;
            }
        }
};


int main(){
    int a,b;
    cout<<"enter number of vertices and edges";
    cin>>a>>b;
    graph g1(a,b);
    g1.addedges();
    g1.prims();
    return 0;
}