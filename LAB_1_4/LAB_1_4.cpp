#include <iostream>
using namespace std;

bool isSorted(int arr[], int n, int index = 0)
{
    if (index == n - 1)
        return true; // ถ้าถึงตัวสุดท้าย แสดงว่าเรียงแล้ว
    if (arr[index] > arr[index + 1])
        return false;                   // ถ้าพบตัวที่ไม่เรียงลำดับ
    return isSorted(arr, n, index + 1); // ตรวจสอบตัวถัดไปแบบ recursive
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (isSorted(arr, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
