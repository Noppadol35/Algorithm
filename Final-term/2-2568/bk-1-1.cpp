#include <iostream>
#include <cmath>
using namespace std;

int coutnter = 0;

void permute(int x[], int start, int end)
{

    if (start == end)
    {
        int pos1 = -1;
        int pos2 = -1;
        for (int i = 0; i <= end; i++)
        {
            if (x[i] == 1)
                pos1 = i;
            if (x[i] == 2)
                pos2 = i;
        }
        if (abs(pos1 - pos2) == 1)
        {
            coutnter++;
        }
        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap(x[start], x[i]);
        permute(x, start + 1, end);
        swap(x[start], x[i]);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[20];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    permute(arr, 0, n - 1);

    cout << coutnter << endl;
    return 0;
}