#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}
int paritition(int arr[], int st, int end)
{
    int pivot = arr[end];
    int j = st - 1;

    for (int i = st; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[j + 1], &arr[end]);
    return j + 1;
}

int kthSmallest(int arr[], int st, int end, int k)
{

    int parIndex = paritition(arr, st, end);

    if (parIndex == k - 1)
        return arr[parIndex];
    if (parIndex > k - 1)
        return kthSmallest(arr, st, parIndex - 1, k);
    else
        return kthSmallest(arr, parIndex + 1, end, k);
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int k = 9;

    if (k > 7)
        cout << "Not found...";
    else
    {
        int ans = kthSmallest(arr, 0, 6, k);
        cout << "K th smallest element is = " << ans;
    }

    return 0;
}