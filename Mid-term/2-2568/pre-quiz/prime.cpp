#include <iostream>
using namespace std;

void mergeSortFunction(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        mergeSortFunction(arr, l, mid, r);
    }
}


int main()
{
    int n = 8;
    int arr[] = {1, 8, 5, 9, 2, 5, 4, 6};
    // 8 | 1 8 5 9 2 5 4 6 = 1 5 5 9 6 4 2

    mergeSort(arr, 0, n - 1);

    int find_min = arr[0];

    if (find_min % 2 == 0){
        check_even = 1;
    } else {
        check_even = 0;
    }

    if (check_even == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            {
                cout << arr[i] << " ";
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] % 2 == 0)
            {
                cout << arr[i] << " ";
            }
        }
    }

    if (check_even == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            {
                cout << arr[i] << " ";
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] % 2 == 0)
            {
                cout << arr[i] << " ";
            }
        }
    }
}