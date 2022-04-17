#include <bits/stdc++.h>
using namespace std;

static int cmp = 0;
static int swapCount = 0;

void swap(int *a, int *b)
{
    ++swapCount;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int st, int end)
{
    int pivot = arr[end];
    int j = st - 1;

    for (int i = st; i < end; i++)
    {
        cmp++;
        if (arr[i] < pivot)
        {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j + 1], &arr[end]);

    return j + 1;
}

void quickSort(int arr[], int st, int end)
{
    if(st < end)
    {
        int partitionIndex = partition(arr, st, end);
        quickSort(arr, st, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

int main()
{
    int arr[] = {54,65,34,76,78,97,46,32,51,21};
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    cout<<endl;
    quickSort(arr, 0, 9);

    cout << cmp << endl;
    cout<< swapCount <<endl;

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}