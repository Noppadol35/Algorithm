#include <iostream>
using namespace std;

long long memo[51];

long long fib(int n) {
    if (n < 2) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main () {
    for(int i = 0; i < 51; i++) {
        memo[i] = -1; 
    }
    cout << fib(10) << endl;
    return 0;
}
