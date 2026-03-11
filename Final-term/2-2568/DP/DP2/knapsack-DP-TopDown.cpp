#include <iostream>
#include <vector>

using namespace std;

int memo[105][105];

int knapsack(int n, int k, int weight[], int value[]) {
    if(n == 0 || k == 0) return 0;
    if(memo[n][k] != -1) return memo[n][k];

    if(weight[n-1] <= k){
        return memo[n][k] = max(value[n-1] + knapsack(n-1, k-weight[n-1], weight, value), knapsack(n-1, k, weight, value));
    } else {
        return memo[n][k] = knapsack(n-1, k, weight, value);
    }
}

int main() {
    int weight[5] = { 1,3,4,5 }, value[5] = { 1,4,5,7 };
    int n = 4, k = 7;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            memo[i][j] = -1;
        }
    }

    cout << knapsack(n, k, weight, value) << endl;
    return 0;
}