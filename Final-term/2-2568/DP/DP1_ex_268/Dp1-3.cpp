#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    // รับค่า n และ m
    if (cin >> n >> m) {
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        dp[1][1] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}