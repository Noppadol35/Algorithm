#include <iostream>
#include <vector>

using namespace std;

int memo[105][105];

int C(int i, int j) {
    return 2 * i + j;
}

int P(int i, int j) {
    if (i == 0) return 3 * j;
    if (j == 0) return 2 * i;
    
    if (memo[i][j] != -1) return memo[i][j];
    
    return memo[i][j] = min({P(i - 1, j) + 2, P(i, j - 1) + 3, P(i - 1, j - 1) + C(i, j)});
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            memo[i][j] = -1;
        }
    }
    cout << P(n, m) << endl;
    return 0;
}