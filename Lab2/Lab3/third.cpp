#include<bits/stdc++>
using namespace std;

int main()
{
    int arr[] = {2, 2, 5 ,1 ,8 ,4 ,8};

    unordered_map<int ,int>mp;

    for(int i = 0 ; i < arr.size() ; i++)
    {
        mp[arr[i]]++;
    }

    vector<int>ans;

    for(auto it : mp)
    {
        ans.push_back(it);_
    }

    for(int i = 0 ; i < ans.size() ; i++)
        cout<<ans[i];
}