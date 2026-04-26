#include<iostream>
using namespace std;

bool isSafe(int x[], int k, int i){
    for(int j = 0; j < k; j++){
        if(x[j] == i || abs(j - k) == abs(x[j] - i)){
            return false;
        }
    }
    return true;
}

void nqueen(int k, int n, int x[]){
    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    if(k == n){
        cout << "ans: ";
        for(int i = 0; i < n; i++){
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int row = 0; row < n; row++){
        if(isSafe(x, k, row)){
            x[k] = row;
            nqueen(k + 1, n, x);
        }
    }
}

int main () {
    int n = 4;

    int x[100] = {};
    for(int i = 0; i < n; i++){
        x[i] = i + 1;
    }

    nqueen(0, n, x);
    return 0;
}