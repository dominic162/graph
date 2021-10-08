#include<iostream>
using namespace std;

void helper(int * arr , bool * visited ,long long int cmx ,long long int cmn ,long long int &ans , int ind ,long long int crr , const int &n , int k){

    if(visited[ind] == true){
        
        cmn = min(cmn , crr);
        cmx = max(cmx , crr);
        if(k == 1){
            ans = min(ans , cmx - cmn);
        }
        return ;
    }

    if(k == 0){
        return ;
    }

    int r = (ind + 1)%n;
    visited[ind] = true;
    helper(arr , visited , cmx , cmn , ans , r , crr + arr[ind] , n , k);

    cmn = min(cmn , crr);
    cmx = max(cmx , crr);
    helper(arr , visited , cmx , cmn , ans , r , arr[ind] , n , --k);

    visited[ind] = false;

    return ;
}

int main(){

    int n , k;
    cin>>n>>k;

    int * arr = new int [n];

    for(int i = 0 ; i < n ; ++i){
        cin>>arr[i];
    }

    long long int ans = INT_MAX;

    bool * visited = new bool [n];
    for(int i = 0 ; i < n ; ++i){
        visited[i] = false;
    }

    for(int i = 0 ; i < n ; ++i){
        
        long long int cmx = INT_MIN;
        long long int cmn = INT_MAX;


        helper(arr , visited , cmx , cmn , ans , i , 0 , n , k);
        
    }

    cout<<ans<<endl;

    delete []visited;
    delete []arr;
    return 0;
}