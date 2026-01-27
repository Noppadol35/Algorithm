#include <iostream>
#include <cmath>
using namespace std;
// 2. ฟังก์ชันนับจำนวนหลัก (แทน .length() ของ string)
int getLength(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

// 3. ฟังก์ชันหาค่ามากสุด (แทน max ใน algorithm)
int getMax(int a, int b)
{
    return (a > b) ? a : b;
}

long long multiply(long long a, long long b)
{
    // Step 1: หาความยาว n
    int lenA = getLength(a);
    int lenB = getLength(b);
    int n = getMax(lenA, lenB);

    // Step 2: Base Case (ถ้าเหลือ 1 หลัก ให้คูณเลย)
    // เงื่อนไข: ถ้า n เป็น 1 หรือเป็น 0
    if (n <= 1)
    {
        return a * b;
    }

    // Step 3: Partition (แบ่งตัวเลขด้วยคณิตศาสตร์)
    // ใช้การหารและ modulo แทนการตัด string
    int mid = n / 2;
    long long divisor = pow(10, mid); // ตัวหารเพื่อแยกหลัก (เช่น 100)

    // a = a1 * 10^(mid) + a2
    // เช่น 4568 / 100 = 45 (a1)
    // เช่น 4568 % 100 = 68 (a2)
    long long a1 = a / divisor;
    long long a2 = a % divisor;
    long long b1 = b / divisor;
    long long b2 = b % divisor;

    // Step 4-7: Recursive Calls
    long long A = multiply(a1, b1);
    long long B = multiply(a2, b1);
    long long C = multiply(a1, b2);
    long long D = multiply(a2, b2);

    // แสดงผลเฉพาะรอบแรกสุด (Top Level) เพื่อให้เห็น Step ตามโจทย์
    if (n == 4 && a == 4568)
    {
        cout << "Partition a (4568): a1=" << a1 << ", a2=" << a2 << endl;
        cout << "Partition b (3275): b1=" << b1 << ", b2=" << b2 << endl;
        cout << "Calculate A (a1*b1): " << A << endl;
        cout << "Calculate B (a2*b1): " << B << endl;
        cout << "Calculate C (a1*b2): " << C << endl;
        cout << "Calculate D (a2*b2): " << D << endl;
    }

    // Step 8: Return ผลลัพธ์
    // สูตร: A * 10^n + (B + C) * 10^(n/2) + D
    // หมายเหตุ: n ในสูตรคณิตศาสตร์เทียบเท่ากับ mid*2 ในโค้ดส่วนนี้
    long long term1 = A * pow(10, mid * 2);
    long long term2 = (B + C) * pow(10, mid);
    long long term3 = D;

    return term1 + term2 + term3;
}

int main()
{
    long long a = 4568;
    long long b = 3275;

    long long result = multiply(a, b);

    cout << result << endl;

    return 0;
}