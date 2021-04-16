//graph ds methods

#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<stack>
using namespace std;

class graph{
    private:
        int edges,vertex;    
        map<int,list<int>> cnt;
        bool directed;
        int* ind;

    public:
        //adds edge
        void addedge(int a,int b){
            cnt[a].push_back(b);
            ++ind[a];
            if(!directed){
                cnt[b].push_back(a);
                ++ind[b];
            }
        }

        void bfsdis(int source,bool visited[]){
            queue<int> q1;
            int temp;
            visited[source]=true;
            q1.push(source);
            while(!q1.empty()){
                temp=q1.front();
                cout<<q1.front()<<" ";
                q1.pop();
                list<int>::iterator it1=cnt[temp].begin();
                for(;it1!=cnt[temp].end();++it1){
                    if(visited[*it1]==false){
                        q1.push(*it1);
                        visited[*it1]=true;
                    }
                }

            }

            cout<<"\n";
            return ;
        }

        void bfs(){ //replace void with int if need to calculate no of disconnected graphs
            bool visited[vertex];
            //int count=0;
            for(int i=0;i<vertex;++i){
                visited[i]=false;
            }
            for(int i=0;i<vertex;i++){
                if(visited[i]==false){
                    bfsdis(i,visited);
                    //count++;
                }
            }
            //return count; if we need to calculate no of disconnected graph
            return ;
        }

        //dfs of a graph

        void dfsdis(int source,bool visited[]){
            stack<int> st1;
            int temp;
            st1.push(source);
            visited[source]=true;
            while(!st1.empty()){
                temp=st1.top();
                st1.pop();
                cout<<temp<<" ";
                list<int>::iterator it1=cnt[temp].begin();
                for(;it1!=cnt[temp].end();it1++){
                    if(visited[*it1]==false){
                        st1.push(*it1);
                        visited[*it1]=true;
                    }
                }
            }
            cout<<"\n";
            return ;
        }

        void dfs(){
            bool visited[vertex];
            for(int i=0;i<vertex;i++){
                visited[i]=false;
            }
            for(int i=0;i<vertex;i++){
                if(visited[i]==false){
                    dfsdis(i,visited);
                }
            }
            return ;
        }


        //display adjacency list
        void display(){
            cout<<"Adjacency list is:\n";
            map<int,list<int>>::iterator it1=cnt.begin();
            for(;it1!=cnt.end();++it1){
                list<int>::iterator it2=it1->second.begin();
                for(;it2!=it1->second.end();++it2){
                    cout<<*it2<<" ";
                }

                cout<<endl;

            }
        }

        //checks cycle in a graph

        bool cycleud(int source,bool visited[]){

            stack<int> st1;
            visited[source]=true;
            st1.push(source);
            int temp,parent=-1;
            while(!st1.empty()){

                temp=st1.top();
                st1.pop();
                list<int>::iterator it1=cnt[temp].begin();
                for(;it1!=cnt[temp].end();++it1){
                    if(visited[*it1]==false){
                        visited[*it1]=true;
                        st1.push(*it1);
                    }
                    else{
                        if(*it1!=parent && *it1!=temp){
                            return true;
                        }
                    }
                }
                parent=temp;

            }

            return false;

        }

        bool cycled(){
            queue<int> q1;
            int count=0;
            for(int i=0;i<vertex;++i){
                if(ind[i]==0){
                    q1.push(i);
                }
            }
            int temp;
            while(!q1.empty()){
                temp=q1.front();
                q1.pop();
                list<int>::iterator it1=cnt[temp].begin();
                for(;it1!=cnt[temp].end();++it1){
                    --ind[*it1];
                    if(ind[*it1]==0){
                        q1.push(*it1);
                    }
                }
                ++count;
            }
            return count!=vertex;
        }
        
        bool checkcycle(){
            bool visited[vertex];
            for(int i=0;i<vertex;++i){
                visited[i]=false;
            }
            if(directed){
                if(cycled()){
                    return true;
                }
            }
            else{
                for(int i=0;i<vertex;++i){
                    if(visited[i]==false){
                            if(cycleud(i,visited))
                                return true;
                    }
                }
            }

            return false;


        }

        graph(int v,int e,char d){
            
            vertex = v;
            
            edges = e;
            ind=new int[vertex];
            if(d=='d'){
                directed=true;
            }
            else{
                directed=false;
            }
            for(int i=0;i<vertex;++i){
                cnt[i];
                ind[i]=0;
            }

        }
};


int main(){

    int e,v;
    char temp='u';
    cout<<"Enter d for directed graph and u for undirected graph: ";
    cin>>temp;
    cout<<"Enter no of vertices and edges: ";
    cin>>v>>e;
    graph g1(v,e,temp);
    cout<<"Enter edges: ";
    for(int i=0;i<e;i++){

        int a,b;
        cin>>a>>b;
        g1.addedge(a,b);

    }
    g1.display();

    //cout<<g1.bfs(); if need to calculate number of disconnected graphs
    cout<<"BFS of graph is:\n";
    g1.bfs();

    cout<<"DFS of graph is:\n";
    g1.dfs();

    cout<<"\n";
    if(!g1.checkcycle()){
        cout<<"No ";
    }
    cout<<"Cycle present\n";
    return 0;
}