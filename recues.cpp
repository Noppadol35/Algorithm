#include <iostream>
using namespace std;

int recues(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    return arr[n - 1] + recues(arr, n - 1);
}

int main()
{
    int n = 0;
    cin >> n;

    int arr[] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int res = recues(arr, n);

    cout << res << endl;
}