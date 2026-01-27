#include <iostream>
using namespace std;

// ---------- swap ----------
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// ---------- Partition ----------
int Partition(int arr[], int l, int r) {
    int pivot = arr[l];
    int i = l;
    int j = r + 1;

    while (true) {
        do { i++; } while (i <= r && arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);

        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

// ---------- Quicksort ----------
void QuickSort(int arr[], int l, int r) {
    if (l < r) {
        int s = Partition(arr, l, r);
        QuickSort(arr, l, s - 1);
        QuickSort(arr, s + 1, r);
    }
}

// ---------- check exists ----------
bool exists(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return true;
    return false;
}

// ---------- main ----------
int main() {
    int N;
    cin >> N;

    int A[100], B[100];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    // sort both lists
    QuickSort(A, 0, N - 1);
    QuickSort(B, 0, N - 1);

    // ---------- Intersection ----------
    for (int i = 0; i < N; i++) {
        if (exists(B, N, A[i])) {
            cout << A[i] << " ";
        }
    }
    cout << endl;

    // ---------- Union ----------
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    for (int i = 0; i < N; i++) {
        if (!exists(A, N, B[i])) {
            cout << B[i] << " ";
        }
    }

    return 0;
}
