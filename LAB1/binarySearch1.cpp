#include<iostream>
using namespace std;

bool binarySearch(int arr[], int n , int key)
{
    int st = 0 ;
    int end = n-1;

    while(st <= end)
    {
        int mid = st + end / 2;

        if(arr[mid] == key)
            return true;
        else if(arr[mid] < key)
            st= mid+1 ;
        else
            end = mid-1;        
    }
    return false;
}



int main()
{
    int n , key;
    cin>>n;

    int arr[n];

    for(int i=0 ; i < n ; i++)
        cin>>arr[i];

    cout<<"Enter an key ";
    cin>>key;

    binarySearch(arr , n , key) == true ?cout<<"key is Present" : cout<<"Key is Not Present";
    return 0;
}