#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// ฟังก์ชันเพื่อค้นหาค่าสูงสุด k อันดับแรก
void findTopK(const vector<int> &A, int k, vector<int> &topK)
{
    for (int num : A)
    {
        // แทรกตัวเลขลงใน topK หากยังไม่เต็ม หรือหากพบค่าที่มากกว่าใน topK
        if (topK.size() < k)
        {
            topK.push_back(num);
        }
        else
        {
            // หาค่าที่น้อยที่สุดใน topK และแทนที่หาก num มากกว่า
            int minIndex = 0;
            for (int i = 1; i < topK.size(); i++)
            {
                if (topK[i] < topK[minIndex])
                {
                    minIndex = i;
                }
            }
            if (num > topK[minIndex])
            {
                topK[minIndex] = num;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<int> topK;
    findTopK(A, k, topK);

    // คำนวณค่าเฉลี่ยของ topK
    double sum = 0;
    for (int num : topK)
    {
        sum += num;
    }
    double average = sum / k;

    // แสดงผลลัพธ์โดยใช้ทศนิยม 2 ตำแหน่ง
    cout << fixed << setprecision(2) << average << endl;

    return 0;
}
