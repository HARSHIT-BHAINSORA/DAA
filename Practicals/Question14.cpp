#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(int arr[] , int n , int k)
{
    int st = 0 , end = n-1;

    vector<int>ans;

    while(st < end)
    {
        if(arr[st] + arr[end] == k)
        {
            ans.push_back(arr[st]);
            ans.push_back(arr[end]);
            return ans;
        }
        else if(arr[st] + arr[end] > k)
            end--;
        else
            st++;  
    }

    return ans;
}

void merge(int arr[] , int st , int end , int mid)
{
    int n1 = mid-st+1;
    int n2 = end-mid;

    int a[n1];
    int b[n2];

    for(int i = 0 ; i < n1 ; i++)
        a[i] = arr[st+i];
    for(int i = 0 ; i < n2 ; i++)
        b[i] = arr[mid+1+i];

    int ptr1 = 0 , ptr2 = 0 , k = st;
    while(ptr1 < n1 && ptr2 < n2)
    {
        if(a[ptr1] < b[ptr2])
            arr[k++] = a[ptr1++];
        else
            arr[k++] = b[ptr2++];    
    }

    while(ptr1 < n1)
        arr[k++] = a[ptr1++];
    while(ptr2 < n2)
        arr[k++] = b[ptr2++];            
}


void mergeSort(int arr[] , int st , int end)
{
    if(st < end)
    {
        int mid = (st+end)/2;

        mergeSort(arr , st  , mid);
        mergeSort(arr , mid+1 , end);
        merge(arr , st ,end , mid);
    }
}

int main()
{
    int arr[] = {4 , 5, 1, 7, 3, 9, 0};

    mergeSort(arr , 0 , 6);

    for(int i=0 ; i < 7 ; i++)
        cout<<arr[i] << " " ;

    cout << endl;
    int k ;
    cin >> k;

    vector<int> ans = twoSum(arr, 7, k);
    if(!ans.empty())
       {
           for(auto it :ans)
                cout<<it << " ";
       } 
    else{
        cout<<"Not found";
    }  
    return 0; 
}