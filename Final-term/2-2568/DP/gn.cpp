#include <iostream>
using namespace std;

long long gn(int n) {
    long long memo[n + 1];
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    for (int i = 3; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2] - memo[i - 3];
    }
    return memo[n];
}

int main() {
    cout << gn(7) << endl;
    return 0;
}