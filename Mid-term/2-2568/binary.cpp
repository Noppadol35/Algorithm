#include <iostream>
using namespace std;

void searchNearest(int A[], int n, int M, int k)
{
    // 1) sort A
    sort(A, A + n);

    // 2) binary search หา index i ที่ใกล้ M ที่สุด
    int left = 0, right = n - 1;
    int i = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (A[mid] == M)
        {
            i = mid;
            break;
        }
        else if (A[mid] < M)
        {
            i = mid; // เก็บตำแหน่งล่าสุดที่น้อยกว่า M
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // 3) ตั้ง left และ right ตาม pseudocode
    int L = i - 1;
    int R = i;

    // 4) ขยายช่วงจนได้ k ตัว
    while ((R - L - 1) < k)
    {

        if (L < 0)
        {
            R++;
        }
        else if (R >= n)
        {
            L--;
        }
        else if (abs(A[L] - M) > abs(A[R] - M))
        {
            R++;
        }
        else
        {
            L--;
        }
    }

    // แสดงผล
    cout << "Nearest " << k << " elements to " << M << " are: ";
    for (int j = L + 1; j < R; j++)
        cout << A[j] << " ";
    cout << endl;
}

int main()
{
    int A[] = {10, 12, 15, 17, 18, 20, 25};
    int n = 7;

    int M = 8;
    int k = 2;

    searchNearest(A, n, M, k);

    return 0;
}