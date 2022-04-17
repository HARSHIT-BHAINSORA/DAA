#include <iostream>
using namespace std;

static int countCmp = 0;

int merge(int arr[], int st, int end, int mid)
{
    int inversionCount = 0;
    int n1 = mid - st + 1;
    int n2 = end - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[st + i];
    }

    for (int j = 0; j < n2; j++)
    {
        b[j] = arr[mid + 1 + j];
    }

    int ptr1 = 0, ptr2 = 0, k = st;
    int ptr3 = st;
    while (ptr1 < n1 && ptr2 < n2)
    {
        countCmp += 1;
        if (a[ptr1] <= b[ptr2])
        {
            arr[k++] = a[ptr1++];
            ptr3++;
        }
        else
        {
            arr[k++] = b[ptr2++];
            inversionCount = inversionCount + (mid - ptr3 + 1);
        }
        
    }

    while (ptr1 < n1)
        arr[k++] = a[ptr1++];
    

    while (ptr2 < n2)
        arr[k++] = b[ptr2++];
    return inversionCount;  
}

int merge_sort(int arr[], int st, int end)
{
    int inversionCount = 0;
    if (st < end)
    {
        int mid = (st + end) / 2;

        inversionCount += merge_sort(arr, st, mid);
        inversionCount += merge_sort(arr, mid + 1, end );
        inversionCount += merge(arr, st, end, mid ); 
        
    }

    return inversionCount;
    
}

int main()
{
    int arr[] = {23 ,65 ,21 ,76,46,89,45,32};

    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";

    cout << endl;
    int ans = merge_sort(arr, 0, 7 );
   
    cout << "The inversion count is = ";
    cout <<  ans << endl;
    cout << countCmp << endl;
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    return 0;
}