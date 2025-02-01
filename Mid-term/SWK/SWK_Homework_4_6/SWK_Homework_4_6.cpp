#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

int ar[10000];
int ar2[1000000];
int ct[10000];

void mg(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int a[n1], b[n2];

    for (i = 0; i < n1; i++)
    {
        a[i] = ar[i + l];
    }
    for (i = 0; i < n2; i++)
    {
        b[i] = ar[i + m + 1];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            ar[k] = a[i];
            i++;
        }
        else
        {
            ar[k] = b[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        ar[k] = a[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ar[k] = b[j];
        j++;
        k++;
    }
}

void mgsort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r - 1) / 2;

        mgsort(l, m);
        mgsort(m + 1, r);
        mg(l, m, r);
    }
}

int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    mgsort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << ar[i];
    }
    cout << endl;
    int k = 0, j;

    int ar3[5];
    for (int i = 0; i < n; i++)
    {
        j = 0;
        while (ar[i] > 0)
        {
            int tmp = ar[i] % 10;
            ar3[j] = tmp;
            ar[i] /= 10;
            j++;
        }
        j--;

        for (int p = j; p >= 0; p--)
        {
            ar2[k] = ar3[p];
            k++;
        }
    }

    int maxf = 1, v;
    int f = 1, vn = ar2[0];
    ct[ar2[k - 1]] = 1;

    for (int i = 1; i < k; i++)
    {
        if (ar2[i] == vn)
        { // same
            f += 1;
            if (f > maxf)
            { // find max of all
                v = ar2[i];
                maxf = f;
            }
            //			if(f > ct[ar2[i]]){ // find max for one number
            //				ct[ar2[i]] = f;
            //			}
        }
        else
        {

            if (f > ct[ar2[i - 1]])
            { // find max for one number
                ct[ar2[i - 1]] = f;
            }
            f = 1;
            vn = ar2[i];
        }
    }
    //	cout << v << endl << ar2[0];

    //	cout << maxf;

    for (int i = 0; i < 1000; i++)
    {
        if (ct[i] == maxf)
        {
            cout << i << " ";
        }
    }

    cout << endl << ar2[0];

    for (int i = 1; i < k; i++)
    {
        if (ar2[i] != ar2[i - 1])
        {
            cout << ar2[i];
        }
    }

    return 0;
}