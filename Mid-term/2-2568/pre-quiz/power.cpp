#include <iostream>
using namespace std;

long long power(int a, int n) {
    if (n == 0) return 1;
    long long half = power(a, n / 2);

    if (n % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}

int main() {
    int a, n;
    cin >> a >> n;
    cout << power(a, n);
    return 0;
}