/*
    Samsung question research center;
*/

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
    public:
        int x,y,cost;
        Node(int x1 , int y1 , int cst){
            this->x = x1;
            this->y = y1;
            this->cost = cst;
        }
};

void bfs(int ** road , int x , int y , const int &n){
    
    queue<Node> q;

    vector<vector<bool>> visited(n , vector<bool> (n , false));
    visited[x][y] = true;
    q.push(Node(x,y,0));

    int mx[4] = {-1 , 0 , 1 , 0};
    int my[4] = { 0 , 1 , 0 ,-1};

    while(!q.empty()){

        Node crr = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; ++i){
            int cx = crr.x + mx[i];
            int cy = crr.y + my[i];

            if(cx >= 0 && cx < n && cy >= 0 && cy < n && road[cx][cy] != -1 && visited[cx][cy] == false){
                visited[cx][cy] = true;
                road[cx][cy] = max(road[cx][cy] , crr.cost + 1);
                q.push(Node(cx , cy , crr.cost + 1));
            }

        }

    }

    return ;
}

int main(){

    int n; //order of matrix;
    cin>>n;

    int ** road = new int * [n];
    for(int i = 0 ; i < n ; ++i){
        road[i] = new int [n];

        for(int j = 0 ; j < n ; ++j){
            int x;
            cin>>x;
            if(x == 0){
                road[i][j] = -1;
            }
            else{
                road[i][j] = 0;
            }
        }
    }


    int q;
    cin>>q; // rare elements;
    pair<int,int> pr[q];

    for(int i = 0 ; i < q ; ++i){
        int x,y;
        cin>>x>>y;
        pr[i].first = x;
        pr[i].second = y;
    }

    int ans = INT_MAX;

    for(int i = 0 ; i < q ; ++i){
        bfs(road , pr[i].first , pr[i].second , n);
    }

    for(int i = 0 ; i < n ; ++i){

        for(int j = 0 ; j < n ; ++j){
            if(road[i][j] != -1){
                ans = min(ans , road[i][j]);
            }
        }

    }

    cout<<ans;

    for(int i = 0 ; i < n ; ++i){   
        delete []road[i];
    }
    delete []road;
    return 0;
}