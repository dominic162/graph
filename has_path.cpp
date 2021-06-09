#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Graph{
    private:
        bool ** adj_mat;
        int V,E;
    
    public:

        void set_edges(){
            
            cout<<"Enter edges: ";
            for(int i = 0 ; i < E ; ++i){
                int v1,v2;
                cin>>v1>>v2;
                adj_mat[v1][v2] = true;
            }

        }

        bool has_path_help(bool * visited , int s , int e){
            if(s == e || adj_mat[s][e]){
                return true;
            }

            visited[s] = true;
            for(int i = 0 ; i < V ; ++i){

                if(adj_mat[s][i] && !visited[i]){
                    if(has_path_help(visited , i , e)){
                        return true;
                    }
                }

            }

            return false;
        }

        bool has_path(int s , int e){

            bool * visited = new bool [V];

            bool ans = has_path_help(visited , s, e);

            delete []visited;

            return ans;
        }


        vector<int> get_path(int s , int e){

            bool * visited = new bool [V];
            
            for(int i = 0 ; i < V ; ++i){
                visited[i] = false;
            }

            vector<int> ans;

            queue<int> q;
            q.push(s);
            visited[s] = true;
            unordered_map<int , int > mp;
            while(!q.empty()){

                int temp = q.front();
                q.pop();
                
                if(temp == e){
                    
                    ans.push_back(e);

                    while(temp != s){
                        ans.push_back(mp[temp]);
                        temp = mp[temp];
                    }
                    
                    temp = ans.size()-1;

                    for(int i = 0 ; i < temp ; ++i){
                        ans[i]    = ans[i]^ans[temp];
                        ans[temp] = ans[i]^ans[temp];
                        ans[i]    = ans[i]^ans[temp];
                        --temp;
                    }
                    break;

                }
                else{
                    
                    for(int i = 0 ; i < V ; ++i){

                        if(adj_mat[temp][i] && !visited[i]){
                            q.push(i);
                            mp[i] = temp;
                            visited[i] = true;
                        }

                    }

                }

            }

            delete []visited;
            return ans;
        }

        Graph(int v , int e):V(v),E(e){
            this->V = v;
            this->E = e;

            adj_mat = new bool * [V];
            for(int i = 0 ; i < V ; ++i){
                adj_mat[i] = new bool [V];

                for(int j = 0 ; j <  V ; ++j){
                    adj_mat[i][j] = false;
                }

            }

        }

};

int main(){

    int v,e;
    cout<<"Enter no of vertices and edges: ";
    cin>>v>>e;

    Graph g1(v,e);
    g1.set_edges();
    
    cout<<"Enter starting and ending: ";
    int st , ed;
    cin>>st>>ed;

    if(g1.has_path(st,ed)){
        vector<int> path = g1.get_path(st,ed);
        for(int i = 0 ; i < path.size() ; ++i){
            cout<<path[i]<<" ";
        }
    }
    else{
        cout<<"Not path";
    }

    return 0;
}