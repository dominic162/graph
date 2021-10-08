#include<iostream>
using namespace std;

class Node{
    public:
        int xt , yt , xb , yb;
};

int helper(int ** plot ,const int &n ,const int &m ,int x , int y){
    
    int cans = 0;

    int low = 0 , high;
    high = min(x , y);

    while(low <= high){

        int md = (low + high)>>1;

        int sx = x - md , sy = y - md;

        int count = plot[x][y];
        
        if(sx != 0){
            count -= plot[sx-1][y];
        }

        if(sy != 0){
            count -= plot[x][sy-1];
        }

        if(sx != 0 && sy != 0){
            count += plot[sx-1][sy-1];
        }

        if(count <= 1){
            cans = md + 1;
            low = md + 1;
        }
        else{
            high = md - 1;
        }

    }

    return cans;
}

int main(){

    int T;
    cin>>T;

    for(int t = 0  ; t < T ; ++t){
        int n,m;
        cin>>n>>m;

        int ** plot = new int * [n];
        for(int i = 0 ; i < n ; ++i){
            plot[i] = new int [m];
            for(int j = 0 ; j < m ; ++j){
                plot[i][j] = 0;
            }
        }
        int sk; //no of sinkhole
        cin>>sk;

        for(int i = 0 ; i < sk ; ++i){
            int x,y;
            cin>>x>>y;
            plot[x][y] = 1;
        }

        for(int i = 0 ; i < n ; ++i){
            int temp = 0;
            for(int j = 0 ; j < m ; ++j){
                temp += plot[i][j];
                plot[i][j] = temp;
                if(i != 0){
                    plot[i][j] += plot[i-1][j];
                }
            }
        }

        Node ans;
        int marea = 0;

        for(int i = 0 ; i < n ; ++i){
            
            for(int j = 0 ; j < m ; ++j){
                
                int carea = helper(plot , n , m , i , j);
                if(carea > marea){
                    marea = carea;
                    int cx = i - carea + 1;
                    int cy = j - carea + 1;
                    ans.xt = cx;
                    ans.yt = cy;
                    ans.xb = i;
                    ans.yb = j;
                }
            }

        }

        cout<<"#"<<t<<" "<<ans.xt<<" "<<ans.yt<<" "<<ans.xb<<" "<<ans.yb<<" "<<endl;

    }

    return 0;
}