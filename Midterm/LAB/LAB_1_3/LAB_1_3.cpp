#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int time_s[1000000];

int main()
{
    int n, max_v = 0, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        time_s[k] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        time_s[k + 1] -= 1;
        if (k > max_v)
        {
            max_v = k;
        }
    }

    for (int i = 1; i <= max_v; i++)
    {
        time_s[i] += time_s[i - 1];
    }

    int max_t = 0, st, en;

    for (int i = 0; i <= max_v; i++)
    {
        if (time_s[i] > max_t)
        {
            max_t = time_s[i];
            st = i;
            en = i;
        }
        if (time_s[i] == max_t && i == en + 1)
        {
            en = i;
        }
    }

    cout << st << " " << en << " " << max_t << endl;

    return 0;
}
