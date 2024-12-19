#include <iostream>
using namespace std;

int main()
{

    int a[1000] = {0};
    int n, target;

    cin >> n ;
    cin >> target;

    for (int i = 0; i < n; i++)
    {
        int v = 0;
        cin >> v;
        a[i] = v;
    }

    bool found = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == target)
            {
                cout << a[i] << " " << a[j] << endl;
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