#include <iostream>
#include <vector>
using namespace std;

int counter = 0;

void permute(int arr[], int start, int end)
{
    if (start == end)
    {
        int position1 = -1;
        int position2 = -1;
        for (int i = 0; i <= end; i++)
        {
            if (arr[i] == 1)
            {
                position1 = i;
            }
            if (arr[i] == 2)
            {
                position2 = i;
            }
        }
        if (abs(position1 - position2) == 1)
        {
            counter++;
        }
        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap(arr[start], arr[i]);
        permute(arr, start + 1, end);
        swap(arr[start], arr[i]);
    }
}

int main()
{
    int n;

    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    permute(arr, 0, n - 1);
    cout << counter << endl;

    return 0;
}