/*https://www.careercup.com/question?id=5652067409461248*/

#include<iostream>
using namespace std;

int helper(int ** arr , int row , short int safe , short int cl , bool bomb){
    
    if(row < 0 || cl < 0 || cl >= 5 || (arr[row][cl] == 2 && safe == 0 && bomb == false)){
        return 0;
    }
    
    int cans = 0;

    if(safe > 0){
        safe--;
    }
    else{
        if(arr[row][cl] == 2){
            bomb = false;
            safe = 4;
        }
    }

    cans = helper(arr , row - 1 , safe , cl - 1, bomb);
    cans = max(cans , helper(arr , row - 1 , safe , cl, bomb));
    cans = max(cans , helper(arr , row - 1 , safe , cl + 1, bomb));
    
    if(arr[row][cl] == 1){
        cans++;
    }

    return cans;
}

int main(){

    int row;
    cin>>row;
    int ** arr = new int * [row + 1];

    for(int i = 0 ; i < row ; ++i){
        arr[i] = new int [5];
        for(int j = 0 ; j < 5 ; ++j){
            cin>>arr[i][j];
        }
    }
    arr[row] = new int [5];
    for(int i = 0 ; i < 5 ; ++i){
        arr[row][i] = 0;
    }
    cout<<helper(arr , row , 0 , 2 , true);

    for(int i = 0 ; i < row ; ++i){
        delete []arr[i];
    }
    delete []arr;

    return 0;
}