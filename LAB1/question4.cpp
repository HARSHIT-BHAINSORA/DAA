#include <iostream>
using namespace std;

void noOfTimes(int arr[], int n, int target)
{
    int st = 0, end = n - 1;
    int leftMost = 0;

    while (st <= end)
    {
        int mid = (st + end) / 2;

        if (arr[mid] == target)
        {
            leftMost = mid;
            end = mid - 1;
        }

        else if (arr[mid] < target)
            st = mid + 1;
        else
            end = mid - 1;
    }

    st = 0, end = n - 1;
    int rightMost = 0;
    while (st <= end)
    {
        int mid = (st + end) / 2;

        if (arr[mid] == target)
        {
            rightMost = mid;
            st = mid + 1;
        }
        else if (arr[mid] < target)
            st = mid + 1;
        else
            end = mid - 1;
    }

    if (leftMost == 0 && rightMost == 0)
        cout << "Target is not present";
    else
    {
        cout << "Target is present" << endl;
        cout << target << "=" << rightMost - leftMost + 1;
    }
}

int main()
{
    int n, key;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter an key ";
    cin >> key;

    noOfTimes(arr, n, key);
    return 0;
}
