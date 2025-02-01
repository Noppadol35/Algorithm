#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[r]);
        int p = i + 1;

        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
}

int binary_search(int arr[], int l, int r, int target)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1; // ไม่พบค่า
}

int main()
{
    int n, k;
    cin >> n >> k;

    if (n < 2 || n > 10000 || k < 1 || k > 100000)
    {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 1 || arr[i] > 10000)
        {
            return 0;
        }
    }

    quick_sort(arr, 0, n - 1);

    int min_diff = INT_MAX;
    int res_i = -1, res_j = -1;

    for (int i = 0; i < n - 1; i++)
    {
        int target = k - arr[i];
        int j = binary_search(arr, i + 1, n - 1, target);

        if (j != -1)
        { // ถ้าพบค่า arr[j] ที่ทำให้ arr[i] + arr[j] = k
            int diff = abs(arr[i] - arr[j]);
            if (diff < min_diff)
            {
                min_diff = diff;
                res_i = i;
                res_j = j;
            }
        }
    }

    if (res_i != -1 && res_j != -1)
    {
        cout << arr[res_i] << " " << arr[res_j] << endl;
    }
    else
    {
        cout << "No valid pair found" << endl;
    }

    return 0;
}
