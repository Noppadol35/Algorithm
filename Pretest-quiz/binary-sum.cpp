#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binary_search(int a[], int l, int r, int i, int target)
{

    int mid = (l + r) / 2;

    while (l <= r)
    {

        if (i + a[mid] == target)
        {
            return mid;
        }

        if (target > i + a[mid])
        {
            return binary_search(a, mid + 1, r, i, target);
        }
        else
        {
            return binary_search(a, l, mid - 1, i, target);
        }
    }
    return -1;
}

int main()
{

    int n = 6;
    int _min = 99999;
    int min_i = 0;
    int min_j = 0;
    int a[] = {8, 7, 5, 4, 2, 3};
    sort(a, a + n);
    int k = 10;
    for (int i = 0; i < n; i++)
    {

        int j = binary_search(a, i + 1, n - 1, a[i], k);

        if (a[i] + a[j] == k)
        {
            if (abs(a[i] - a[j]) < _min)
            {
                _min = abs(a[i] - a[j]);
                min_i = i;
                min_j = j;
            }
        }
    }

    cout << a[min_i] << " " << a[min_j] << " " << _min;

    return 0;
}