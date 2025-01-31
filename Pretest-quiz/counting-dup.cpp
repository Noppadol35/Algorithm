#include <iostream>

using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j <= r; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i + 1;
}

void quick_sort(int arr[], int l , int r){
    if(l < r){
        int p = partition(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
}

int binary_search_first(int a[], int l, int r, int k, int index)
{

    int mid = (l + r) / 2;

    while (l <= r)
    {
        // เจอ
        if (k == a[mid])
        {
            index = mid;
            return binary_search_first(a, l, mid - 1, k, index);
        }

        if (k > a[mid])
        {
            return binary_search_first(a, mid + 1, r, k, index);
        }
        else
        {
            return binary_search_first(a, l, mid - 1, k, index);
        }
    }
    return index;
}

int binary_search_last(int a[], int l, int r, int k, int index)
{

    int mid = (l + r) / 2;

    while (l <= r)
    {
        // เจอ
        if (k == a[mid])
        {
            index = mid;
            return binary_search_last(a, mid + 1, r, k, index);
        }

        if (k > a[mid])
        {
            return binary_search_last(a, mid + 1, r, k, index);
        }
        else
        {
            return binary_search_last(a, l, mid - 1, k, index);
        }
    }
    return index;
}

int main()
{

    int n = 10; //int n = sizeof(arr)/sizeof(arr[0]);
    int a[] = {11, 11, 6, 4, 2, 5, 4, 4, 2, 6};
    int target = 4;

    quick_sort(a, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    int F = binary_search_first(a, 0, n - 1, target, -1);
    int L = binary_search_last(a, 0, n - 1, target, -1);

    cout << (L - F) + 1 << endl;
}
