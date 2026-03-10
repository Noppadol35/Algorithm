#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    // รับค่าจำนวนสินค้าและเงินเริ่มต้น [cite: 41]
    if (cin >> n >> k) {
        vector<int> prices(n);
        // รับราคาสินค้าแต่ละชิ้น [cite: 41]
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }

        vector<int> dp(k + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= prices[i]; --j) {
                if (dp[j - prices[i]] != -1) {
                    dp[j] = max(dp[j], dp[j - prices[i]] + 1);
                }
            }
        }
        // แสดงจำนวนสินค้าที่มากที่สุด [cite: 42]
        cout << (dp[k] == -1 ? 0 : dp[k]) << "\n";
    }
    return 0;
}