#include <iostream>
using namespace std;

int k;
int arr[100] = {};

void printSubSet(int arr[], int R)
{
    for (int i = 0; i <= R; i++)
    {
        if (arr[i] == 1)
            cout << arr[i - 1] << " ";
    }
    cout << endl;
}

void subSet1(int arr[], int L, int R, int sum)
{
    if (sum == k)
    {
        printSubSet(arr, R);
        return;
    }
    if (L == R)
        return;
    return;
    if (sum > k)
    {
        return;
    }
    else
    {
        arr[L + 1] = 1;
        sum = sum + arr[L];
        subSet1(arr, L + 1, R, sum);
        arr[L + 1] = 0;
        sum = sum - arr[L];
        subSet1(arr, L + 1, R, sum);
    }
}

int main()
{
    cin >> k;

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    subSet1(arr, 0, 5, 0);

    return 0;
}