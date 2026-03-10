#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    // รับจำนวนเงินที่ต้องการแลก (n) 
    if (cin >> n >> k) { 
        vector<int> coins(k);
        // รับมูลค่าของเหรียญที่แตกต่างกัน 
        for (int i = 0; i < k; ++i) {
            cin >> coins[i];
        }

        // ใช้ long long ป้องกัน overflow
        vector<long long> dp(n + 1, 0); 
        dp[0] = 1; // มี 1 วิธีในการสร้างเงิน 0 บาท

        for (int i = 0; i < k; ++i) {
            for (int j = coins[i]; j <= n; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        
        // แสดงจำนวนวิธีแลกเหรียญทั้งหมด 
        cout << dp[n] << "\n";
    }
    return 0;
}