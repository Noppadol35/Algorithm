#include<iostream>
using namespace std;

long long memo[100][100];

long long cnk(int n, int k) {
    if(n < k) return 0;
    if(k == 0 || k == n) return 1;
    if(memo[n][k] != 0) return memo[n][k];
    return memo[n][k] = cnk(n - 1, k - 1) + cnk(n - 1, k);
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << cnk(n, k) << endl;
    return 0;
}