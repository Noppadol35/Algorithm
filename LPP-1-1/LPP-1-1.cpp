#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// concount and sort
int main()
{
    int num;
    cin >> num;

    vector<int> A(num);

    for (int i = 0; i < num; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int group = 1;
    for (int i = 1; i < num; i++)
    {
        if (A[i] - A[i - 1] > 1)
        {
            group++;
        }
    }

    cout << group << endl;

    return 0;
}