/* https://www.hackerearth.com/problem/algorithm/question-7-4/ */
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int x,y,type,ln;
        Node(int x , int y , int t, int l){
            this->x = x;
            this->y = y;
            this->type = t;
            this->ln = l;
        }
};

inline bool safe(int x , int y , int n , int m , int l){
    if(x >= 0 && x < n && y >= 0 && y < m && l > 0){
        return true;
    }
    return false;
}

int main(){
    
    bool up[7] = {true , true , false , true , false , false , true};
    bool dn[7] = {true , true , false , false , true , true , false};   
    bool lf[7] = {true , false , true , false , false , true , true};
    bool rf[7] = {true , false , true , true , true , false , false};

    int t;
    cin>>t;

    for( ; t > 0 ; t--){

        int n , m , x , y , l;
        cin>>n>>m>>x>>y>>l;

        int ** pipe = new int * [n];

        for(int i = 0 ; i < n ; ++i){
            pipe[i] = new int [m];
            for(int j = 0 ; j < m ; ++j){
                cin>>pipe[i][j];
            }
        }

        int ans = 0;

        if(pipe[x][y] != 0 && l > 0){

            queue<Node> q;
            q.push(Node(x,y,pipe[x][y] - 1 , l - 1));
            ans++;
            pipe[x][y] = 0;
            while(!q.empty()){
                
                Node crr = q.front();
                q.pop();

                if(up[crr.type]){
                    if(safe(crr.x - 1, crr.y , n , m , crr.ln) && pipe[crr.x-1][crr.y] != 0 && dn[pipe[crr.x-1][crr.y]-1]){
                        q.push(Node(crr.x-1 , crr.y , pipe[crr.x-1][crr.y] - 1 , crr.ln - 1));
                        pipe[crr.x-1][crr.y] = 0;
                        ans++;
                    }
                }

                if(dn[crr.type]){
                    if(safe(crr.x + 1, crr.y , n , m , crr.ln) && pipe[crr.x+1][crr.y] != 0 && up[pipe[crr.x+1][crr.y]-1]){
                        q.push(Node(crr.x+1 , crr.y , pipe[crr.x+1][crr.y] - 1 , crr.ln-1));
                        pipe[crr.x+1][crr.y] = 0;
                        ans++;
                    }
                }

                if(lf[crr.type]){
                    if(safe(crr.x , crr.y - 1 , n , m , crr.ln) && pipe[crr.x][crr.y - 1] != 0 && rf[pipe[crr.x][crr.y-1]-1]){
                        q.push(Node(crr.x , crr.y - 1 , pipe[crr.x][crr.y - 1] - 1 , crr.ln - 1));
                        pipe[crr.x][crr.y-1] = 0;
                        ans++;
                    }
                }

                if(rf[crr.type]){
                    if(safe(crr.x, crr.y+1 , n , m , crr.ln) && pipe[crr.x][crr.y+1] != 0 && lf[pipe[crr.x][crr.y+1]-1]){
                        q.push(Node(crr.x, crr.y+1 , pipe[crr.x][crr.y+1] - 1 , crr.ln - 1));
                        pipe[crr.x][crr.y+1] = 0;
                        ans++;
                    }
                }

            }

        }

        cout<<ans<<"\n";
        for(int i = 0 ; i < n ; ++i){
            delete []pipe[i];
        }
        delete []pipe;
    }

    return 0;
}