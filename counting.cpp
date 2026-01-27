#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int a[] = {3,6,4,7,8};
    int b[] = {4,6,4,9,10};

    int a_map[10000] = {0};
    int check_union[100000] = {0};
    int check_intersection[100000] = {0};
    int ans_u[10000];
    int ans_in[10000];
    int k_u = 0;
    int k_in = 0;

    for (int i = 0; i < n; i++)
    {
        a_map[a[i]]++;
        if (check_union[a[i]] == 0)
        {
            check_union[a[i]]++;
            ans_u[k_u] = a[i];
            k_u++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (check_union[b[i]] == 0)
        {
            check_union[b[i]]++;
            ans_u[k_u] = b[i];
            k_u++;
        }

        if (a_map[b[i]] > 0 && check_intersection[b[i]] == 0)
        {
            check_intersection[b[i]]++;
            ans_in[k_in] = b[i];
            k_in++;
        }
    }
    for (int i = 0; i <= 10000; i++)
    {
        if (check_union[i] > 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    for (int i = 0; i <= 10000; i++)
    {
        if (check_intersection[i] > 0)
        {
            cout << i << " ";
        }
    }
}