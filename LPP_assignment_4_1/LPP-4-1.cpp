#include <iostream>
using namespace std;

int countTarget(int arr[], int l, int r, int target)
{
    if (l > r)
    {
        return 0;
    }

    if (l == r)
    {
        return (arr[l] == target);
    }

    int mid = l + (r - l) / 2;
    int leftCount = countTarget(arr, l, mid, target);
    int rightCount = countTarget(arr, mid + 1, r, target);

    return leftCount + rightCount;
}

int main()
{
    int n,k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = countTarget(arr, 0, n - 1, k);

    if(result == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }
    
    return 0;
}