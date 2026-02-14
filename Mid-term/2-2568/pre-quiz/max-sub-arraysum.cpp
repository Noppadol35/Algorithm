#include<iostream>
using namespace std;

int maxSubArray(int arr[], int l, int m, int r){
    int sum_left = 0;
    int min_left = -99999;

    for (int i = m; i >= l; i--)
    {
        sum_left = sum_left + arr[i];
        min_left = max(min_left, sum_left);
    }

    int sum_right = 0;
    int min_right = -99999;

    for (int i = m + 1; i <= r; i++)
    {
        sum_right = sum_right + arr[i];
        min_right = max(min_right, sum_right);
    }

    return min_left + min_right;
}

int maxSubArrayRec(int arr[], int l, int r){
    if(l == r)return arr[l];
    int mid = l + (r - l) / 2;
    
    return max(maxSubArrayRec(arr, l, mid),
            max(maxSubArrayRec(arr, mid + 1, r),
                maxSubArray(arr, l, mid, r)));
}

int main(){
    int arr[] = {16, -25, 2, -54, 36, 9 ,-12, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    maxSubArrayRec(arr, 0, n-1);
    return 0;
}