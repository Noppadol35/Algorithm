#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Partition(int arr[], int l, int r)
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

void Quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = Partition(arr, l, r);
        Quick_sort(arr, l, p - 1);
        Quick_sort(arr, p + 1, r);
    }
}

int main()
{
    int n = 10;
    int arr[] = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};

    Quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}