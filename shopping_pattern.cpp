#include <bits/stdc++.h>
using namespace std;

int find_ans(int n , vector<vector<int>> &edge){
    int ans = 0;

    unordered_set<int> adj[n];

    for(int i = 0 ; i < edge.size() ; ++i){
        adj[edge[i][0]].insert(edge[i][1]);
        adj[edge[i][1]].insert(edge[i][0]);
    }

    unordered_set<int> visited;
    unordered_set<int> tr;

    for(int i = 0 ; i < n ; ++i){

        auto it1 = adj[i].begin();
        
        for( ; it1 != adj[i].end() ; ++it1){
            
            auto it2 = adj[*it1].begin();
            for( ; it2 != adj[*it1].end() ; ++it2){
                if(*it2 == i){
                    continue;
                }
                if(adj[*it2].find(i) != adj[*it2].end()){
                    if(tr.find(i) == tr.end()){
                        tr.insert(i);
                    }
                    if(tr.find(*it1) == tr.end()){
                        tr.insert(*it1);
                    }
                    if(tr.find(*it2) == tr.end()){
                        tr.insert(*it2);
                    }
                }

            }

        }
 
    }
    
    for(int i = 0 ; i < edge.size() ; ++i){
        int r = 0;
        if(tr.find(edge[i][0]) != tr.end()){
            r++;
        }
        if(tr.find(edge[i][1]) != tr.end()){
            r++;
        }

        if(r == 1){
            ans++;
        }

    }

    return ans;
}

int main() {
    int n,size;
    cin>>n>>size;

    vector<vector<int>> edge;

    for(int i = 0 ; i < size ; ++i){
        int x , y;
        cin>>x>>y;
        vector<int> vr;
        vr.push_back(x-1);
        vr.push_back(y-1);
        edge.push_back(vr);
    }

    cout<<find_ans(n , edge);

    return 0;
}
