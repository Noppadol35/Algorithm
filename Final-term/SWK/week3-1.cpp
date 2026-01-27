#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------- Partition (Hoare) ----------
int Partition(int arr[], int l, int r, int n) {
    int p = arr[l];
    int i = l;
    int j = r + 1;

    cout << "\nPartition [" << l << "," << r << "] ";
    cout << "Pivot = " << p << endl;

    while (true) {
        do {
            i++;
        } while (arr[i] < p && i <= r);

        do {
            j--;
        } while (arr[j] > p);

        if (i >= j)
            break;

        cout << "swap arr[" << i << "]=" << arr[i]
             << " , arr[" << j << "]=" << arr[j] << endl;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        printArray(arr, n);
    }

    cout << "swap pivot arr[" << l << "]=" << arr[l]
         << " , arr[" << j << "]=" << arr[j] << endl;

    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    printArray(arr, n);

    return j;
}

// ---------- Quicksort ----------
void QuickSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int s = Partition(arr, l, r, n);
        QuickSort(arr, l, s - 1, n);
        QuickSort(arr, s + 1, r, n);
    }
}

// ---------- main ----------
int main() {
    int arr[] = {16, 25, 2, 54, 36, 9, 12, 66};
    int n = 8;

    cout << "Initial array:\n";
    printArray(arr, n);

    QuickSort(arr, 0, n - 1, n);

    cout << "\nFinal sorted array:\n";
    printArray(arr, n);

    return 0;
}
