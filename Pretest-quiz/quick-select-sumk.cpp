#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
int quickSelect(int arr[], int l, int r, int k)
{
    if (l == r)
    {
        return arr[l];
    }
    int p = partition(arr, l, r);
    if (k == p)
    {
        return arr[p];
    }
    if (k < p)
    {
        return quickSelect(arr, l, p - 1, k);
    }
    else
    {

        return quickSelect(arr, p + 1, r, k);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int arr_k[k];
    for (int j = 0; j < k; j++)
    {
        cin >> arr_k[j];
    }
    

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += quickSelect(arr, 0, n - 1, arr_k[i] - 1);
    }
    cout << sum;

    return 0;
}