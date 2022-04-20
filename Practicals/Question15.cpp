#include<bits/stdc++.h>
using namespace std;

void intersection(vector<int> arr1 , vector<int> arr2 )
{
    vector<int>ans;
    int i = 0 , j = 0;

    int n = arr1.size();
    int m = arr2.size();
   
    
    while(i < n && j < m)
    {
        if(arr1[i] == arr2[j])
        {
            if(ans.empty())
                ans.push_back(arr1[i]);
            else if(ans.back() != arr1[i])
                ans.push_back(arr1[i]); 
            i++,j++;       
        }

        else if(arr1[i] < arr2[j])
            i++;
        else if(arr1[i] > arr2[j])
            j++;
        else    
            i++ , j++;
    }

    for(auto it : ans)
        cout<<it<<" ";

}

int main()
{
    vector<int>arr1;

    int n , m ;
    cin >> n;
    cin>> m;
    for(int i = 0 ; i < n ; i++)
    {
        int ele ;
        cin>>ele;
        arr1.push_back(ele);
    }

    sort(arr1.begin() , arr1.end());
    vector<int>arr2;
    
    for(int i = 0 ; i < m ; i++)
    {
        int ele ;
        cin>>ele;
        arr2.push_back(ele);
    }
    sort(arr2.begin() , arr2.end());
   
    intersection(arr1 , arr2);
    
}   