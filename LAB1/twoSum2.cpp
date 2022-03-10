
#include<bits/stdc++>
using namespace std;





int main()
{
    int n , sum;
    cin>>n;

    int arr[n];

    for(int i=0 ; i < n ; i++)
        cin>>arr[i];

   
    vector<pair{int , int}> v = twoSum(arr , n , sum);

    for(auto it : v)
    {
        cout<<it.first << ","<< it.second<<endl;
    }
    return 0;
}