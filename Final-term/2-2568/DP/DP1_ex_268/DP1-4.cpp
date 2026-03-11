#include <iostream>
#include <vector>

using namespace std;

int memo[105][105];

int productRelation(int n, int k, int productList[]) {
    if(n == 0 || k == 0) return 0;
    if(memo[n][k] != -1) return memo[n][k];

    return memo[n][k] = max(productRelation(n - 1, k, productList), productRelation(n - 1, k - 1, productList ) + 1);
}

int main() {
    int n, k;
    cin >> n >> k;

    int productList[100];
    for (int i = 0; i < n; i++) {
        cin >> productList[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            memo[i][j] = -1;
        }
    }

    cout << productRelation(n, k, productList) << endl;
    return 0;
}