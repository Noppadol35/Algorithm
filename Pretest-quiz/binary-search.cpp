#include <iostream>
using namespace std;

int binary(int arr[], int l, int r, int target)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // คำนวณ mid ทุกครั้งใน loop

        if (arr[mid] == target)
        {
            return mid; // เจอค่าเป้าหมาย
        }
        else if (target < arr[mid])
        {
            return binary(arr, l, mid - 1, target); // ค้นหาทางซ้าย
        }
        else
        {
            return binary(arr, mid + 1, r, target); // ค้นหาทางขวา
        }
    }
    return -1; // ไม่พบค่า
}

int main()
{
    int n = 10;
    int arr[] = {1, 2, 2, 2, 4, 5, 6, 10, 11, 11}; // อาร์เรย์ต้องเรียงลำดับแล้ว
    int k = 11;

    cout << binary(arr, 0, n - 1, k); // ค้นหา k ในอาร์เรย์

    return 0;
}
