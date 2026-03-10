#include<iostream>
using namespace std;


long long cnk(int n, int k) {
    long long arr[n + 1][k + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(n < k) return 0;
            if(j == 0 ) arr[i][j] = 1;
            if(i == j) arr[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i > j) arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    return arr[n][k];
}

int main(){
    int n, m;
    cin >> n >> m;

    cout << cnk(n, m) << endl;
    return 0;
}