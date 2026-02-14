#include <iostream>
using namespace std;

int a[] = {25, 10, 6, 4};
int k = 10;

void print_sol(int x[], int n){
    for(int j = 1; j <= n; j++){
        cout << x[j] << " ";
        
    }
    cout << endl;
}

void subset1(int x[], int l, int r, int sum){
    if(sum == k){
        print_sol(x, r);
        return;
    }

    if(l == r){
        
        return;
    }
    if(sum > k){
        return;
    } else {
        x[l + 1] = 1;
        sum = sum + x[l];
        subset1(x, l+1, r, sum);
        x[l + 1] = 0;
        sum = sum - x[l];
        subset1(x, l+1, r, sum);
    }


}

int main() {
    int n = 4;
    int x[n+1];
    subset1(x, 0, n, 0);
    return 0;
}