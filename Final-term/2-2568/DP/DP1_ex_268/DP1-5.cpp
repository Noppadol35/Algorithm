#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memo[105][105];

// ฟังก์ชันหาค่า C(i, j) = 2i + j [cite: 46]
int C(int i, int j) {
    return 2 * i + j;
}

int P(int i, int j) {
    // Base cases [cite: 46]
    if (i == 0) return 3 * j;
    if (j == 0) return 2 * i;
    
    // คืนค่าหากเคยคำนวณไว้แล้ว
    if (memo[i][j] != -1) return memo[i][j];
    
    // ความสัมพันธ์ Recurrence relation 
    return memo[i][j] = min({P(i - 1, j) + 2, P(i, j - 1) + 3, P(i - 1, j - 1) + C(i, j)});
}

int main() {
    int n, m;
    // รับค่า n และ m [cite: 48]
    if (cin >> n >> m) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                memo[i][j] = -1;
            }
        }
        // แสดงผลลัพธ์ของ P(n,m) [cite: 50]
        cout << P(n, m) << "\n";
    }
    return 0;
}