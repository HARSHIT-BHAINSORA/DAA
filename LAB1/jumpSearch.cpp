#include<iostream>
#include<math.h>
using namespace std;

bool jumpSearch(int arr[] , int n , int target)
{
    int i = 1;
    int left = 0;   //starting of block 
    int right = pow(2,i++); // end of block

    while(arr[right] <= target && right < n)
    {
        // we are not is correct one skip it...

        left = right;
        right = pow(2,i++);

        if(right > n-1)  // excced last index. to avoid overflow take it to n
            right = n;

    }

    // if we find out the correct block excute linear search

    for(int i = left ; i < right ; i++)
    {
        if(arr[i] == target)
            return true;
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

    jumpSearch(arr , n , key) == true ?cout<<"key is Present" : cout<<"Key is Not Present";
    return 0;
}

/* Time Complexity is 
n - no.of element  ,  m - no. of block if we reached then implement linear search m-1 
n / m . m-1 if diff. it , it become sqrt(n) O(sqrt(n))  regular jump search.*/