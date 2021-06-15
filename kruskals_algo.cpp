/*
    Kruskal's algo for minimum spanning tree;
*/

#include<iostream>
#include<algorithm>
using namespace std;

class Edge{
    public:
        int u , v , wt;
};

bool comp(const Edge &a , const Edge &b){
    if(a.wt <= b.wt){
        return true;
    }
    return false;
}

class Graph{
    private:
        int V,E;

        Edge * edge;
    
    public:

        void add_edge(int v1 , int v2 , int w , int i){
            edge[i].u = v1;
            edge[i].v = v2;
            edge[i].wt = w;

            return ;
        }

        Edge * find_mst(){
            sort(edge , edge + E);
            Edge * mst = new Edge [V-1];

            int * par = new int [V];

            for(int i = 0 ; i < V ; ++i){
                par[i] = i;
            }

             


        }

        Graph(int v , int e): V(v), E(e){
            edge = new Edge [E];
        }

};

int main(){

    int v ,e;

    cout<<"Enter no of vertices and edges: ";
    cin>>v>>e;

    Graph g1(v,e);

    cout<<"Enter edges: ";

    for(int i = 0 ; i < e ; ++i){
        int v1 , v2 , w;
        cin>>v1>>v2>>w;
        g1.add_edge(v1,v2,w,i);
    }

    Edge * mst = g1.find_mst();

    return 0;
}