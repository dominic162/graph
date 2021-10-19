/* Leetcode 787 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define ff first
#define ss second

class Solution {
public:

    void del_heap(vector<pair<int,int>> &heap , int i , vector<vector<int>> &ind , int sz , vector<vector<int>> &dist){
        
        while(i != sz - 1){
            int crr = i;
            if(2*i + 1 < sz && dist[heap[2*i+1].ff][heap[2*i+1].ss + 1] < dist[heap[crr].ff][heap[crr].ss + 1]){
                crr = 2*i + 1;
            }

            if(2*i + 2 < sz && dist[heap[2*i+2].ff][heap[2*i+2].ss + 1] < dist[heap[crr].ff][heap[crr].ss + 1]){
                crr = 2*i + 2;
            }  

            if(crr == i){
                break;
            }

            pair<int,int> temp = heap[i];
            heap[i] = heap[crr];
            heap[crr] = temp;
    
            ind[heap[i].ff][heap[i].ss + 1] = i;
            ind[heap[crr].ff][heap[crr].ss + 1] = crr;
            i = crr;
        }

        return ;
    }

    void ins_heap(vector<pair<int,int>> &heap , int i , vector<vector<int>> &ind , int sz , vector<vector<int>> &dist){

        while(i != 0){
            
            int par = (i-1)/2;

            if(dist[heap[i].ff][heap[i].ss + 1] < dist[heap[par].ff][heap[par].ss + 1]){
                pair<int,int> temp = heap[i];
                heap[i] = heap[par];
                heap[par] = temp;
                ind[heap[i].ff][heap[i].ss + 1] = i;
                ind[heap[par].ff][heap[par].ss + 1] = par;
                i = par;
            }
            else{
                i = 0;
            }

        }

        return ;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        for(int i = 0 ; i < flights.size() ; ++i){
            adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }

        vector<pair<int , int>> heap((n+2)*(k+1) , pair<int,int>{-1,-1});
        vector<vector<int>> dist(n , vector<int> (k + 1 , INT_MAX));
        vector<vector<int>> ind(n , vector<int> (k + 1 , -1));

        for(int i = 0 ; i < k + 1 ; ++i){
            dist[src][i] = 0;
        }

        heap[0].ff = src;
        heap[0].ss = k;

        int sz = 1;

        while(sz > 0){

            int cnode = heap[0].ff;
            int crrk  = heap[0].ss;
            
            if(crrk != k){
                ind[cnode][crrk + 1] = -1;
            }

            sz--;
            heap[0].ff = heap[sz].ff;
            heap[0].ss = heap[sz].ss;
            
            del_heap(heap , 0 , ind , sz , dist);

            if(crrk < 0){
                continue;
            }

            for(int i = 0 ; i < adj[cnode].size() ; ++i){
               
                int ngh = adj[cnode][i].ff;
                int ed = adj[cnode][i].ss;
                
                int prln = (crrk == k)?0:dist[cnode][crrk+1];

                if(dist[ngh][crrk] > prln + ed){
                    dist[ngh][crrk] = prln + ed;
                    
                    if(ind[ngh][crrk] == -1){
                        
                        heap[sz].ff = ngh;
                        heap[sz].ss = crrk - 1;

                        ind[ngh][crrk] = sz;
                        sz++;
                    }

                    ins_heap(heap , ind[ngh][crrk] , ind , sz , dist);

                }

            }

        }
        int ans = INT_MAX;
        for(int i = 0 ; i <= k ; ++i){
            ans = min(ans , dist[dst][i]);
        }

        return (ans == INT_MAX)?-1:ans;
    }
};

int main(){
    return 0;
}