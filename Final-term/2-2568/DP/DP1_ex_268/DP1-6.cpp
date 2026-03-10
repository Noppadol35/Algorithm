#include <iostream>
#include <vector>

using namespace std;

int cost[55][55];
int memo[55][55];
int x2, y_2;

int solve(int r, int c) {
    // กรณีถึงจุดหมาย
    if (r == x2 && c == y_2) return cost[r][c];
    // กรณีเดินออกนอกกริด [cite: 54]
    if (r > x2 || c > y_2) return 1e9; 
    
    if (memo[r][c] != -1) return memo[r][c];
    
    // เดินลง หรือ เดินขวา
    return memo[r][c] = cost[r][c] + min(solve(r + 1, c), solve(r, c + 1));
}

int main() {
    int n, m;
    // รับจำนวนแถวและคอลัมน์ [cite: 60]
    if (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> cost[i][j]; // รับรายการ cost [cite: 61]
                memo[i][j] = -1;
            }
        }
        int x1, y_1;
        // รับตำแหน่งเริ่มต้นและสิ้นสุด [cite: 62]
        cin >> x1 >> y_1 >> x2 >> y_2;
        
        cout << solve(x1, y_1) << "\n";
    }
    return 0;
}