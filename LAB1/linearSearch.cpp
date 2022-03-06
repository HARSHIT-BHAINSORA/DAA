#include<iostream>
using namespace std;


bool linearSearch(int arr[] , int n , int key)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == key)
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

    linearSearch(arr , n , key) == true ?cout<<"key is Present" : cout<<"Key is Not Present";
    return 0;
}


/* n = 5
 arr[5] = {1 , 4, 2 , 5, 3}
 key = 5;

 no.of comparison is - 1 + 
