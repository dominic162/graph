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

        Edge * edges_list;
    
    public:

        void add_edge(int v1 , int v2 , int w , int i){
            edges_list[i].u = v1;
            edges_list[i].v = v2;
            edges_list[i].wt = w;

            return ;
        }

        int find_rep(int x , int * par){
            if(par[x] == x){
                return x;
            }

            par[x] = find_rep(par[x] , par);            

            return par[x];

        }

        void do_union(int x , int y , int * par , int * rank){
            int x_rep = find_rep(x , par);
            int y_rep = find_rep(y , par);

            if(rank[x_rep] > rank[y_rep]){
                par[y_rep] = x_rep;
            }
            else{
                if(rank[x_rep] < rank[y_rep]){
                    par[x_rep] = y_rep;
                }
                else{
                    par[x_rep] = y_rep;
                    rank[y_rep]++;
                }
            }

            return ;
        }

        Edge * find_mst(){
            sort(edges_list , edges_list + E , comp);
            Edge * mst = new Edge [V-1];

            int * par = new int [V];
            int * rank = new int [V];

            for(int i = 0 ; i < V ; ++i){
                par[i]  = i;
                rank[i] = 0;
            }

            int i = 0 , j = 0;

            while(i < V-1){

                Edge &e = edges_list[j];
                int v1_rep = find_rep(e.u , par);
                int v2_rep = find_rep(e.v , par);

                if(v1_rep != v2_rep){
                    mst[i++] = e;
                    do_union(e.u , e.v , par , rank);
                }

                ++j;
            }

             
            delete []par;
            delete []rank;
            return mst;
        }

        Graph(int v , int e): V(v), E(e){
            edges_list = new Edge [E];
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

    cout<<"Edges in Minimum spanning tree and their weight: ";
    for(int i = 0 ; i < v-1 ; ++i){
        cout<<mst[i].u<<" "<<mst[i].v<<" "<<mst[i].wt<<endl;
    }

    delete []mst;
    return 0;
}