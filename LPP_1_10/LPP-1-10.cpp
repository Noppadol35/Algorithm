#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int max_size = 100000;
    int arr[max_size] = {};
    int max_hour = 0;

    int n = 0;
    cin >> n;
    if (n <= 0 || n > 100000)
        return 0;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        if (start < 0 || end < 0)
            return 0;
        arr[start] = arr[start] + 1;
        if (end + 1 < max_size)
        {
            arr[end + 1] -= 1;
        }
        max_hour = max(end, max_hour);
    }
    max_hour++;

    int arr_hour[max_hour] = {};
    for (int i = 1; i < max_hour; ++i)
    {
        arr_hour[i] = arr_hour[i - 1] + arr[i];
    }

    int max_time = 0;
    int start_time = 0;
    int end_time = 0;
    for (int i = 0; i < max_hour; i++)
    {
        if (arr_hour[i] > max_time)
        {
            max_time = arr_hour[i];
            start_time = i;
            end_time = i;
        }
        else if (arr_hour[i] == max_time)
        {
            if (i == end_time + 1)
            {
                end_time = i;
            }
        }
    }

    cout << start_time << " " << end_time << " " << max_time;
}
