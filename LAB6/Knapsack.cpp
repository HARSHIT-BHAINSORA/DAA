#include<bits/stdc++.h>
using namespace std;


int knapsack(int n , int W , vector<int> profit , vector<int> weg){
    
    if(n == 0 || W == 0)
        return 0;
        
    if(weg[n-1] <= W)
    {
        int pick = profit[n-1]+knapsack(n-1 , W - weg[n-1] , profit , weg);
        int notPick = knapsack(n-1 , W , profit , weg);
        
        return max(pick , notPick);
    }
    
    else{
        return knapsack(n-1 , W , profit , weg);
    }
}


int main(){
    
    vector<int>profit {1 , 2 , 5 ,6};
    vector<int>weg {2 , 3 , 4 , 5};
    
    int W = 8;
    int n = 4;
    
    cout<<"The Maximum Profit is - ";
    cout << knapsack(n , W  , profit , weg);
    return 0;
}