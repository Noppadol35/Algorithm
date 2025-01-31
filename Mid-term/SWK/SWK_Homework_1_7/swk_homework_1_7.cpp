#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int arr[1000] = {0};
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool found = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << arr[i] << " " << arr[j] << endl;
                found = true;
            }
        }
    }

    if (!found)
    {
        cout << -1 << endl;
    }

    return 0;
}
