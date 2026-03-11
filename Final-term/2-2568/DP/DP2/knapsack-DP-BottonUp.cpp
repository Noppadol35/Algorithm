#include <iostream>
#include <vector>

using namespace std;

int memo[105][105];

int knapsackBottomUp(int n, int k, int weight[], int value[]) {
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(i == 0 || j == 0) {
                memo[i][j] = 0;
            } else if(weight[i-1] <= j){
                memo[i][j] = max(value[i-1] + memo[i-1][j-weight[i-1]], memo[i-1][j]);
            } else {
                memo[i][j] = memo[i-1][j];
            }
        }
    }
    return memo[n][k];
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