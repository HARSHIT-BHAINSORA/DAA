#include<iostream>
using namespace std;

int cmpCount=0;

void merge(int arr[] , int st , int end, int mid)
{
    int n1 = mid-st+1;
    int n2 = end-mid;

    int a[n1];
    int b[n2];

    

    for(int i = 0 ; i < n1 ; i++)
        arr[i] = a[st+i];
    for(int j = 0 ; j < n2 ; j++)
        arr[j] = a[mid+1+j];

    int i = 0 , j = 0 , k = st;
    while(i < n1 && j < n2)
    {
        cmpCount++;
        if(arr[i] < arr[j])
            arr[k++] = arr[i++];
        else if(arr[j] < arr[i])
            arr[k++] = arr[j++];    
    }

    while(i < n1)
    {
        arr[k++] = arr[i++];
    }        

    while(j < n2)
    {
        arr[k++] = arr[i++];
    }        
}

 void mergeSort(int arr[] , int low , int high)
 {
    
    if(low >= high)
        return ;
    
    int mid = (low + high)/2;

    mergeSort(arr , low , mid);
    mergeSort(arr , mid+1 , high);
    merge(arr , low , high , mid);

 }

int main()
{
    int arr[7] = {3, 1, 4, 2, 7, 4 ,8};

    mergeSort(arr , 0 , 6);

    cout<<cmpCount;

    for(int i = 0 ; i < 7 ; i++)
    {
        cout<< arr[i]<<" ";
    }
}