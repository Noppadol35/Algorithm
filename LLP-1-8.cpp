#include <iostream>
using namespace std;

int main()
{

    int a[1000] = {0};
    int n;
    cin >> n;
    int maxsum = -100000;
    int start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        int v = 0;
        cin >> v;
        a[i] = v;
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum > maxsum)
            {
                maxsum = sum;
                start = i;
                end = j;
            }
        }
    }

    cout << maxsum << endl;

    return 0;
}