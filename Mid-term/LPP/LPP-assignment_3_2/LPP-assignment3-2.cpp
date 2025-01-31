#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    // int mid = (l + r)/2;
    // if(arr[l] > arr[mid]) swap(arr[l], arr[mid]);
    // if(arr[l] > arr[r]) swap(arr[l], arr[r]);
    // if(arr[mid] > arr[r]) swap(arr[mid], arr[r]);
    // swap(arr[r], arr[mid]);
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
    cout << (i + 1) << " ";
    return i + 1;
}

void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
}

int main()
{
    int n = 8;
    int arr[] = {16, 25, 2, 54, 36, 9, 12 ,66};

    quick_sort(arr, 0, n-1);

    cout << endl;
    for(int i =0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}