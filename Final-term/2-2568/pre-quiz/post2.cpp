#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // สำหรับฟังก์ชัน max

using namespace std;

int bfs(int startI, int startJ, vector<vector<int>> &arr, int n, int c)
{
    int countPa = 0;
    queue<pair<int, int>> q;

    // จุดเริ่มต้น
    q.push({startI, startJ});
    arr[startI][startJ] = 2;
    countPa++;

    while (!q.empty())
    {
        int curI = q.front().first;
        int curJ = q.front().second;
        q.pop();

        // เช็คซ้าย
        if (curJ - 1 >= 0 && arr[curI][curJ - 1] == 1)
        {
            q.push(make_pair(curI, curJ - 1));
            arr[curI][curJ - 1] = 2;
            countPa++;
        }
        // เช็คขวา
        if (curJ + 1 < c && arr[curI][curJ + 1] == 1)
        {
            q.push(make_pair(curI, curJ + 1));
            arr[curI][curJ + 1] = 2;
            countPa++;
        }
        // เช็คบน
        if (curI - 1 >= 0 && arr[curI - 1][curJ] == 1)
        {
            q.push(make_pair(curI - 1, curJ));
            arr[curI - 1][curJ] = 2;
            countPa++;
        }
        // เช็คล่าง
        if (curI + 1 < n && arr[curI + 1][curJ] == 1)
        {
            q.push(make_pair(curI + 1, curJ));
            arr[curI + 1][curJ] = 2;
            countPa++;
        }
    }

    // คืนค่าขนาดของกลุ่มที่นับได้
    return countPa;
}

int main()
{
    int n = 0, c = 0;
    cin >> n >> c;

    vector<int> ans;
    vector<vector<int>> arr(n, vector<int>(c, 0));
    char ch;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> ch;
            if (ch == '#')
                arr[i][j] = 1;
            else if (ch == '.')
                arr[i][j] = 0;
        }
    }

    // ค้นหาและนับขนาดด้วย BFS
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                // เรียกใช้ฟังก์ชัน bfs และเก็บผลลัพธ์ลง ans
                int componentSize = bfs(i, j, arr, n, c);
                ans.push_back(componentSize);
            }
        }
    }

    if (ans.empty()) // ใช้ .empty() แทน .size() == 0 จะอ่านง่ายกว่า
    {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    // หาค่า Max
    int _max = -9999;
    for (int i = 0; i < ans.size(); i++)
    {
        _max = max(_max, ans[i]);
    }

    // นับความถี่
    vector<int> counting(_max + 1, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        counting[ans[i]]++;
    }

    // แสดงผล
    cout << _max << " " << counting[_max] << endl;

    return 0;
}