#include <iostream>

using namespace std;

int x = 0;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quick_sort(int arr[], int l, int r)
{
    x = x + 1;
    if (l < r)
    {
        int p = partition(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
}

int binary_search_first(int a[], int l, int r, int k)
{

    int mid = (l + r) / 2;

    while (l <= r)
    {
        x = x + 1;
        // เจอ
        if (k == a[mid])
        {
            return mid;
        }

        if (k > a[mid])
        {
            return binary_search_first(a, mid + 1, r, k);
        }
        else
        {
            return binary_search_first(a, l, mid - 1, k);
        }
    }
    return -1;
}


int main()
{

    // int n = 4; //int n = sizeof(arr)/sizeof(arr[0]);
    // int arr[] = {1,-2,1,-2};
    // int target = -2;

    int n = 10;
    int arr[] = {60, 70, 70, 60, 60, 70, 70, 70, 70, 50};
    int target = 70;

    quick_sort(arr, 0, n - 1);

    // int F = binary_search_first(arr, 0, n - 1, target, -1);
    // int L = binary_search_last(arr, 0, n - 1, target, -1);

    cout << x << endl;
}
