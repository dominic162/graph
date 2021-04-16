#include<bits/stdc++.h>
using namespace std;

class graph{
    private:
        int vertices,edges;
        unordered_map<string,int> status;
        unordered_map<string,list<string>>mp1;
    public:
        
        void addvertex(string a){
            status[a]=1;
        }
        
        void addedge(string v1,string v2){
            mp1[v1].push_back(v2);
        }
        
        void dfs(string snode){  //dfs of a graph
            stack<string> s1;
            s1.push(snode);
            string r;
            status[r]=2;
            while(!s1.empty()){
                r=s1.top();
                cout<<r<<"->";
                s1.pop();
                status[r]=3;
                list<string>::iterator p;
                for(p=mp1[r].begin();p!=mp1[r].end();p++){
                    if(status[*p]==1){
                        status[*p]=2;
                        s1.push(*p);
                    }
                }
            }
            cout<<"X";
        }
        graph(int v,int e){
            this->vertices=v;
            this->edges=e;
        }
};

int main(){
    int v,e,i;
    string a,v1,v2,snode;
    cout<<"enter number of vertices and edges ";
    cin>>v>>e;
    graph g1(v,e);
    cout<<"enter vertices ";
    for(i=0;i<v;i++){
        cin>>a;
        g1.addvertex(a);
    }
    cout<<"enter vertices which has edge between them ";
    for(i=0;i<e;i++){
        cin>>v1;
        cin>>v2;
        g1.addedge(v1,v2);
    }
    cout<<"enter source node for dfs";
    cin>>snode;
    g1.dfs(snode);
    return 0;
}