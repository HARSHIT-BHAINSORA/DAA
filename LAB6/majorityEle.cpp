#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int arr[5] = {3,5,2,3,2};
    
    int candidate ;
    int count = 0;
    int cnt = 0;
    
    for(int i = 0 ; i < 5 ; i++)
    {
        if(count == 0){
            candidate = arr[i];
            count++;
        }    
        else if(candidate != arr[i])
            count--;
        else 
            count++;
    }
    
    for(int i = 0 ; i < 5 ; i++)
    {
        if(candidate == arr[i])
            cnt++;
    }
    
    if(cnt > 5 /2)
        cout<<candidate;
    else
        cout<<-1;
}