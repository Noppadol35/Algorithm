#include <iostream>
using namespace std;

bool SortOrNot(int arr[], int n)
{
    if (n == 1 || n == 0)
    {
        return true;
    }

    if (arr[n - 1] < arr[n - 2])
    {
        return false;
    }

    return SortOrNot(arr, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (SortOrNot(arr, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
