#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v;

    int n ;
    cin >> n;
    for(int i = 0 ; i < n ;i++)
    {
        char temp ;
        cin >> temp;
        v.push_back(temp);
    }

    int freq[26] = {0};

    for(auto it : v)
    {
        freq[it-'a']++;
    }

    int mx = INT_MIN , ind ;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(mx < freq[i]){
            ind = i;
            mx = freq[i];
        }
    }
    if(mx != 1)
        cout << char(ind+'a') << " - " <<mx;
    else
        cout<<"NO Duplicate founded...";
}