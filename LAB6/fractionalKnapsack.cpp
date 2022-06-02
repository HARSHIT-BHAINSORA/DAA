#include<bits/stdc++.h>
using namespace std;

// #define pair<float , pair<int , int>>  ppi

int main()
{
    vector<int> profit{25 , 24 , 15};
    vector<int> weight{18 , 15 , 10};
    vector<float> pRw ;
    
    for(int i = 0 ; i < 3 ; i++)
    {
        pRw.push_back((float) profit[i] / weight[i]);
    }
    
    
        
    priority_queue<pair<float , pair<int , int>>>maxheap;
    
    for(int i = 0 ; i < 3 ; i++)
    {
        maxheap.push({pRw[i] , {profit[i] , weight[i]}});
    }
    
    // while(!maxheap.empty())
    // {
    //     pair<float , pair<int , int>> ele = maxheap.top();
    //     cout<< ele.first  << "   " << ele.second.first << "    " << ele.second.second << endl;
    //     maxheap.pop();
    // }
    
    int W;
    cout<< "Enter the weight of bag ";
    cin>>W;
    
    float maxProfit = 0.0 ;
    
    while(!maxheap.empty())
    {
        pair<float , pair<int , int>> ele = maxheap.top();
        float pw = ele.first;
        int pro = ele.second.first;
        int weg = ele.second.second;
        
          
        maxheap.pop();
        
        
        if(W > 0  &&  weg <= W)
        {
            W -= weg;
            maxProfit += pro;
        }
        
        else if(W > 0)
        {
            maxProfit += (float) W / weg * pro;
            cout<< "The maximum profit is = " maxProfit ;
            return 0;
        }
    }
    return 0;    
}