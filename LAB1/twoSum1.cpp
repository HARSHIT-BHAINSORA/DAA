// return paris of the given sum

#include<bits/stdc++>
using namespace std;

vector<pair{int ,int}> twoSum(int arr[] , int n , int sum)
{
    vector<pair{int , int}> ans;

    int st = 0 , end = n-1;

    while(st <= end)
    {
        if(arr[st] + arr[end] == sum)
        {
            ans.push_back({st , end});
            end--;
        }
        else if(arr[st] + arr[end] < sum)
        {
            st++;
        }
        else{
            end--;
        }
    }
    return ans;
}


int main()
{
    int n , sum;
    cin>>n;

    int arr[n];

    for(int i=0 ; i < n ; i++)
        cin>>arr[i];

    cout<<"Enter an sum ";
    cin>>sum;

    vector<pair{int , int}> v = twoSum(arr , n , sum);

    for(auto it : v)
    {
        cout<<it.first << ","<< it.second<<endl;
    }
    return 0;
}
