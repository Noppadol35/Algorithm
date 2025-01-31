#include <iostream>
using namespace std;

int Partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void Quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = Partition(arr, l, r);
        Quick_sort(arr, l, p - 1);
        Quick_sort(arr, p + 1, r);
    }
}

int main()
{

    int num;

    cin >> num;

    if (num <= 1 || num >= 1000000)
    {
        return 0;
    }

    int arr[num];
    int index;

    for(int i = 1; i <= 6; i++){
        arr[index] = num % 10;
        num /= 10;
        index++;
    }

    // while (num > 0)
    // {
    //     arr[index] = num % 10;
    //     num /= 10;
    //     index++;
    // }

    Quick_sort(arr, 0, index - 1);

    for (int i = 1; i < index; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}