/*
    Dijkstra's shortest path algo
*/

#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;



class Graph{
    private:
        int V,E;
        list < pair<int, int > > *adj;

    public:

        int djk_algo(int sr , int ds){

            vector<int> dist(V,INT_MAX);
            set< pair < int , int > > st;

            dist[sr] = 0;
            st.insert({0 , sr});

            while(!st.empty()){

                set< pair<int , int > > ::iterator it = st.begin();
                int cdist = it->first;
                int cnode = it->second;
                st.erase(it);

                list< pair < int , int > > ::iterator it1 = adj[cnode].begin();

                while(it1 != adj[cnode].end()){

                    if(it1->second + cdist < dist[it1->first]){
                        if(st.find({dist[it1->first] , it1->first}) != st.end()){
                            st.erase({dist[it1->first] , it1->first});
                        }
                        dist[it1->first] = it1->second + cdist;
                        st.insert({dist[it1->first] , it1->first});
                    }

                    it1++;

                }

            }

            for(int i = 0 ; i < V ; ++i){
                cout<<i<<" "<<dist[i]<<endl;
            }

            return dist[ds];

        }

        void add_edge(int u , int v , int wt){
            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }

        Graph(int v , int e):V(v),E(e){
            adj = new list<pair<int,int> > [V];
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

    cout<<"Enter vertice 1 , vertice 2 , weight of edge: ";
    for(int i = 0 ; i < e ; ++i){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        g1.add_edge(v1,v2,wt);
    }

    int sr,dst;
    cout<<"Enter source and dest: ";
    cin>>sr>>dst;
    
    int distance = g1.djk_algo(sr,dst);
    cout<<"Minimum distance between "<<sr<<" and "<<dst<<" is "<<distance;

    return 0;
}