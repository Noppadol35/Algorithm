#include <iostream>
using namespace std;

int memo[1000][1000];

int triger(int n, int m){
    
    if(n == 1 && m == 1) return 1;
    if(n == 0) return 0;
    if(m == 0) return 0;

    return memo[n][m] = triger(m-1, n) + triger(m, n-1);
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            memo[i][j] = -1;
        }
    }

    cout << triger(n, m) << endl;
    return 0;
}