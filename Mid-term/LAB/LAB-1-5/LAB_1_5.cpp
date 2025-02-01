#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;

    if (n > 10000 || n < 1)
    {
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > 10000 || arr[i] < 1)
        {
            return 0;
        }
    }

    bubble_sort(arr, n);

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}