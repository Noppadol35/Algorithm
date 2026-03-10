#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L;
    // รับค่าความยาวท่อนไม้ L [cite: 74]
    if (cin >> L) {
        vector<int> price(L + 1, 0);
        // รับค่าราคาท่อนไม้ที่ความยาวต่างๆ [cite: 75]
        for (int i = 1; i <= L; ++i) {
            cin >> price[i];
        }

        vector<int> dp(L + 1, 0);
        
        // คำนวณราคาสูงสุดสำหรับแต่ละความยาวตั้งแต่ 1 ถึง L [cite: 71, 72]
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] = max(dp[i], price[j] + dp[i - j]);
            }
        }
        
        // แสดงผลรวมของราคาที่มากที่สุด [cite: 77]
        cout << dp[L] << "\n";
    }
    return 0;
}