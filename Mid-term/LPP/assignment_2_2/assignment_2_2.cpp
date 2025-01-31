#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int minDifference = INT_MAX;
    int left = 0, right = n - 1;

    while (left < right)
    {
        int sum = A[left] + A[right];

        if (sum == k)
        {
            int difference = abs(A[left] - A[right]);
            minDifference = min(minDifference, difference);

            left++;
            right--;
        }
        else if (sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << minDifference << endl;

    return 0;
}
