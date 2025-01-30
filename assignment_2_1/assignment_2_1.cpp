#include <iostream>
using namespace std;

int Binary(int arr[], int l, int r, int k)
{
    if (l > r)
    {
        return -1;
    }

    int mid = l + ((k-arr[l]) * (r - l) / (arr[r] - arr[l]));
    cout << mid << " ";

    if (arr[mid] == k)
    {
        return mid;
    }
    else if (arr[mid] < k)
    {
        return Binary(arr, mid + 1, r, k);
    }
    else
    {
        return Binary(arr, l, mid - 1, k);
    }
}

int main()
{
    int n, target;
    cin >> n >> target;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Binary(arr, 0, n - 1, target);

    return 0;
}
