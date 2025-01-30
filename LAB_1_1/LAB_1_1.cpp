#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// ฟังก์ชัน QuickSort
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int num;
    cin >> num;

    // ตรวจสอบว่า num อยู่ในช่วงที่กำหนด
    if (num <= 0 || num > 1000000)
    {
        return 1;
    }

    int arr[1000000];

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];

        // ตรวจสอบค่าที่ป้อนว่าต้องอยู่ในช่วงที่เหมาะสม
        if (arr[i] < 0 || arr[i] > 1000000)
        {
            return 1;
        }
    }

    // ใช้ QuickSort
    quickSort(arr, 0, num - 1);

    int group = 1;                
    for (int i = 1; i < num; i++) // เริ่มจาก index 1 เพื่อเลี่ยงการเข้าถึง arr[-1]
    {
        if (arr[i] - arr[i - 1] > 1) // หากระยะห่างมากกว่า 1 ให้นับเป็นกลุ่มใหม่
        {
            group++;
        }
    }

    cout << group << endl;

    return 0;
}
