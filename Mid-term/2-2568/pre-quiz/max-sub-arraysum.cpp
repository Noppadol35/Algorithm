#include <iostream>

using namespace std;

int maxsubarraycross(int a[], int l, int mid, int r)
{
    int sum_left = 0;
    int min_left = -9999;

    for (int i = mid; i >= l; i--){
        sum_left = sum_left + a[i];
        min_left = max(min_left, sum_left);
    }

    int sum_right = 0;
    int min_right = -9999;

    for (int i = mid + 1; i <= r; i++){
        sum_right = sum_right + a[i];
        min_right = max(min_right, sum_right);
    }

    return min_left + min_right;
}

int maxsubarray(int arr[], int l, int r)
{
    if (l == r){
        return arr[l];
    }
    int mid = l + (r - l) / 2;
    return max(maxsubarray(arr, l, mid),
    max(maxsubarray(arr, mid + 1, r),
    maxsubarraycross(arr, l, mid, r)));
}

int main()
{
    int arr[] = {16, -25, 2, -54, 36, 9, -12, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = maxsubarray(arr, 0, n - 1);

    cout << result << " ";
    return 0;
}