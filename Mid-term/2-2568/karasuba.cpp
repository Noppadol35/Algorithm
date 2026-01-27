#include <iostream>
#include <cmath>
using namespace std;

// ไม่ใช้ using namespace std; เพื่อความชัดเจนในการเรียกใช้

// ฟังก์ชันหาค่ามากสุด (แทน std::max ใน <algorithm>)
int getMax(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// ฟังก์ชันหาจำนวนหลักของตัวเลข (แทนการแปลงเป็น string)
int getLength(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

long long karatsuba(long long num1, long long num2)
{
    // 1. หาความยาวของตัวเลขทั้งสอง
    int len1 = getLength(num1);
    int len2 = getLength(num2);

    // หา n (ความยาวสูงสุด)
    int n = getMax(len1, len2);

    // 2. Base case: ถ้าเลขเหลือน้อยกว่า 2 หลัก ให้คูณปกติ
    if (n < 2)
    {
        return num1 * num2;
    }

    // 3. แบ่งตัวเลข (Partition)
    int mid = n / 2;
    long long multiplier = pow(10, mid); // ค่า 10^(n/2)

    // แบ่ง num1 เป็น a1 (หน้า), a2 (หลัง)
    long long a1 = num1 / multiplier;
    long long a2 = num1 % multiplier;

    // แบ่ง num2 เป็น b1 (หน้า), b2 (หลัง)
    long long b1 = num2 / multiplier;
    long long b2 = num2 % multiplier;

    // 4. A = Multiply(a1, b1)
    long long A = karatsuba(a1, b1);

    // 5. B = Multiply(a2, b2)
    long long B = karatsuba(a2, b2);

    // 6. C = Multiply(a1 + a2, b1 + b2)
    // แก้ไข typo จากโจทย์ (a1+a1) -> (a1+a2)
    long long C = karatsuba(a1 + a2, b1 + b2);

    // 7. คำนวณผลลัพธ์สุดท้าย
    // สูตร: A * 10^(2*mid) + (C - A - B) * 10^mid + B
    // หมายเหตุ: ใช้ multiplier * multiplier แทน 10^n เพื่อความแม่นยำในกรณี n เป็นเลขคี่

    long long term1 = A * (multiplier * multiplier);
    long long term2 = (C - A - B) * multiplier;

    return term1 + term2 + B;
}

int main()
{
    long long x = 4568;
    long long y = 3275;

    long long result = karatsuba(x, y);

    cout << result;
    return 0;
}