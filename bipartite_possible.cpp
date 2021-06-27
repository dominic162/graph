/*
    Is it possible to bipartite graph
    Leetcode #886
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool comp(const vector<int> &a , const vector<int> &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.size() == 0){
            return true;
        }
        vector<vector<int>> adj(n);
        
        for(int i = 0 ; i < dislikes.size() ; ++i){
            adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        
        bool * color = new bool [n];
        bool * visited = new bool[n];
        for(int i = 0 ; i < n ; ++i){
            visited[i] = false;
        }
        
        queue<int> q;
        
        
        for(int otr = 0 ; otr < n ; ++otr){
            if(visited[otr] == true){
                continue;
            }
            q.push(otr);
            visited[otr] = true;
            color[otr] = true;
            
            while(!q.empty()){

                int par = q.front();
                q.pop();

                for(int i = 0 ; i < adj[par].size() ; ++i ){

                    if(visited[adj[par][i]]){
                        if(color[adj[par][i]] == color[par]){
                            delete []color;
                            delete []visited;
                            return false;
                        }
                    }
                    else{
                        color[adj[par][i]] = !color[par];
                        visited[adj[par][i]] = true;
                        q.push(adj[par][i]);
                    }

                }


            }
        }
        
        delete []color;
        delete []visited;
        return true;
        
    }
};

int main(){

    return 0;
}