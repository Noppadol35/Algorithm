#include <iostream>
#include <vector>
using namespace std;

void shellSortWithSedgewick(vector<int> &arr)
{
    int n = arr.size();
    vector<int> sedgewick;

    for (int i = 0;; i++)
    {
        int h = (i % 2 == 0) ? (9 * (1 << i) - 9 * (1 << (i / 2)) + 1)
                             : (8 * (1 << i) - 6 * (1 << ((i + 1) / 2)) + 1);
        if (h >= n)
            break;
        sedgewick.push_back(h);
    }

    for (int h = sedgewick.size() - 1; h >= 0; h--)
    {
        int gap = sedgewick[h];

        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }

        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    shellSortWithSedgewick(arr);

    return 0;
}
