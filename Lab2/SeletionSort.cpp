// internal sorting {need whole memory of their array}
// 1. bubble ,selection , insertion

// external {take half array in memory} merge sort.

/* inplace  = no extra space taken O(1) <= x <= logn
 outplace = extra space taken 

 stable  = order should be maintaine.
 unstable = opposite of stable.

 -2 45 0 11 -9*/

 // Bubble sort 

#include<iostream>
using namespace std;

void bubbleSort(int arr[] , int n)
{

    int countSwap = 0 ;
    int countCmp = 0
    for(int i = 0 ; i < n-1 ;i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            countCmp++;
            if(arr[j] < arr[j+1])
            {
                countSwap++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 

            }
        }
        if(countSwap == 0)
            break;
    }
    cout << countSwap << " ";
    cout<< countCmp << " " << endl;
}

int main(){
    int arr[5] = {-2 , 45 , 0 , 11 ,-9 };
    bubbleSort(arr , 5);

    for(int i = 0 ; i < 5 ; i++)
    {
        cout<<arr[i];
    }
}

// let analysis 5 3 2 -> cmp = 3 swap = 3 , 


// no.of max cmp - of decre- make incre - n-1 + n-2+ ... + 1 - n(n-1)/2
// worst case o(n^2) 

// best case comparison - n-1
//best case = O(n)