#include<iostream>
using namespace std;

unsigned long long fnk(int n, int k){
    long long arr[n + 1][k + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j == 0 ) arr[i][j] = 1;
            if(i == j) arr[i][j] = 1;
            if(j == 1) arr[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i >= j) 
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 2];
        }
    }

    return arr[n][k];
}

int main(){

    int n, m;
    cin >> n >> m;
    cout << fnk(n, m) << endl;
    return 0;
}