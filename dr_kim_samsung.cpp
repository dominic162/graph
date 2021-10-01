#include<iostream>
#include<vector>
using namespace std;

#define ff first
#define ss second

void dfs(vector<pair<int,int>> &loc , int crr , const int & ed , vector<bool> &visited , int &ans , int cans){

    if(cans > ans){
        return ;
    }

    bool emp = false;

    for(int i = 2 ; i < loc.size() ; ++i){

        if(visited[i] == false){
            emp = true;
            visited[i] = true;

            int r = (abs(loc[i].ff - loc[crr].ff) + abs(loc[i].ss - loc[crr].ss));

            dfs(loc , i , ed , visited , ans , cans + r);

            visited[i] = false;
        }

    }

    if(emp == false){
        cans += abs(loc[crr].ff - loc[ed].ff) + abs(loc[crr].ss - loc[ed].ss);
        ans = min(ans , cans);
    }

    return ;
}

int main(){

    int n;
    cin>>n;
    vector<pair<int,int>> loc(n + 2);

    for(int i = 0 ; i < n + 2 ; ++i){
        cin>>loc[i].ff>>loc[i].ss;
    }

    int ans = INT_MAX;
    vector<bool> visited(n + 2 , false);
    dfs(loc , 0 , 1 , visited , ans , 0);

    cout<<ans;

    return 0;
}