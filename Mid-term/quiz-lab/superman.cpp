#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main (){
    long long x;
    cin >> x;
    long long check = 1 + 8 * x;
    long long sqrt_val = sqrt(check);
    if(sqrt_val * sqrt_val == check){
        int n = (-1 + sqrt_val) / 2;
        if(n * (n + 1) / 2 == x){
            cout << n << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}