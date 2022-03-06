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


/* Time complexity is O(logn)
reson begin   1 it -> n , 2 it -> n/2 , 3 it -> n/2^2 ... k it-> 1
so the limiting  is 1 = n / 2^K
2^k = n (log both side).
k log 2 = log n
k = log n / log 2 = logn base 2  -> O(log n)*/