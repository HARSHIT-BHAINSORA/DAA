#include<bits/stdc++.h>
using namespace std;


int knapsack(int n , int W , int profit[] , int weg[]){
    
    
    int dp[n+1][W+1];
    
    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < W+1 ; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
                continue;
        }
    }
    
    
     for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < W+1 ; j++)
        {
          cout<< dp[i][j]  << " ";
        }
        cout<<endl;
    }
    
    cout << "Hi" << endl;
    
    
    for(int i = 1 ; i < n+1 ; i++)
    {
        for(int j = 1 ; j < W+1 ; j++)
        {
            if(weg[i-1] <= j)
            {
                int pick = profit[i-1] + dp[i-1][j-weg[i-1]];
                int NotPick = dp[i-1][j];
                
                dp[i][j] = max(pick , NotPick);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    
     
    for(int i = 0 ; i < n+1 ; i++)
    {
        for(int j = 0 ; j < W+1 ; j++)
        {
          cout<< dp[i][j]  << " ";
        }
        cout<<endl;
    }
    
    return dp[n][W];
}


int main(){
    
    // vector<int>profit {1 , 2 , 5 ,6};
    //vector<int>weg {2 , 3 , 4 , 5};
    
    int profit[] = {1 , 2 , 5 ,6};
    int weg[] = {2 , 3, 4, 5};
    
    int W = 8;
    int n = 4;
    
    cout<<"The Maximum Profit is - ";
    cout << knapsack(n , W  , profit , weg);
    return 0;
}
