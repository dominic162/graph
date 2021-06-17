/*
    Prim's algo efficient
*/

#include<iostream>
#include<vector>
#include<set>
#define dist  first
#define par   second
#define node  second
#define neigh second
using namespace std;


class Graph{

    private:
        int V,E;
        vector< pair < int , int >> * adj;
    
    public:

        void add_edge(int u , int v , int wt){
            vector<int> v1,v2;
            pair < int , int > p1{wt,v};
            adj[u].push_back(p1);

            p1.neigh = u;
            adj[v].push_back(p1);

            return ;
        }

        void prims(){
            
            vector< pair< int , int > > ans;

            for(int i = 0 ; i < V ; ++i){
                pair<int , int > p1{INT_MAX , -1};
                ans.push_back(p1);
            }

            ans[0].dist  =  0;

            set< pair < int , int > > st;

            for(int i = 0 ; i < V ; ++i){
                pair<int , int > p1{ans[i].dist , i};
                st.insert(p1);
            }

            while(st.size() != 1){

                auto it = st.begin();
                int cnode = it->node;

                st.erase(it);

                for(int i = 0 ; i < adj[cnode].size() ; ++i){
                    
                    int nnode = adj[cnode][i].neigh;
                    int cedge = adj[cnode][i].dist;
                    int ndist = ans[nnode].dist;

                    auto f = st.find({ndist, nnode});
                    if(f != st.end()){

                        if(cedge < ndist){
                            st.erase(f);
                            ans[nnode].dist = cedge;
                            ans[nnode].par  = cnode; 
                            st.insert({ cedge , nnode });
                        }

                    }

                }

            }

            for(int i = 1 ; i < V ; ++i){
                cout<<i<<" "<<ans[i].par<<" "<<ans[i].dist<<endl;
            }

            return ;

        }

        Graph(int v ,int e):V(v),E(e){
            adj = new vector< pair<int , int > > [V];
        }

        ~Graph(){
            delete []adj;
        }

};

int main(){

    int v,e;
    cout<<"Enter no of vertices and edges: ";
    cin>>v>>e;

    Graph g1(v,e);

    cout<<"Enter vertice 1 , vertice 2 and weight: ";

    for(int i = 0 ; i < e; ++i){
        int u,v,wt;
        cin>>u>>v>>wt;
        g1.add_edge(u,v,wt);
    }

    g1.prims();

    return 0;
}