#include<bits/stdc++>
using namespace std;

void parition(int arr ,  int n)
{
    int pivot = arr[n-1];
    int i = st-1;

    for(int j = 0 ; j < n-1 ; j++)
    {
        if(pivot > arr[j])
        {
            i++;
            swap(arr[i] , arr[j]);
        }

        swap(arr[++i] , pivot);
    }
}

void insertionSort(int arr , int n)
{
    int p = parition(arr , n);
    quickSort(arr ,p )
}

int main()
{
    int arr[7] = {3, 1, 4, 2, 7, 4 ,8};

    insertionSort(arr ,6);

    cout<<cmpCount;

    for(int i = 0 ; i < 7 ; i++)
    {
        cout<< arr[i]<<" ";
    }
}