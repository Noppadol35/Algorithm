#include <iostream>
using namespace std;

int a[] = {25, 10, 9, 2};
int k = 12;
int num_count = 0;
void print_sol(int x[], int n){
    for(int j = 1; j <= n; j++){
        if(x[j] == 1){
            cout << a[j-1] << " ";
        }
        
    }
    cout << endl;
}

void subset1(int x[], int l, int r, int sum){
    
    if(sum == k){
        print_sol(x, r);
        return;
    }
    if(l == r){
        //print_sol(x, r);
        return;
    }
    if(sum > k){
        return;
    } else {
        x[l + 1] = 1;
        sum = sum + a[l];
        subset1(x, l+1, r, sum);
        x[l + 1] = 0;
        sum = sum - a[l];
        subset1(x, l+1, r, sum);
        num_count++;
    }


}

int main() {
    int n = 4;
    int x[n+1];
    subset1(x, 0, n, 0);
    cout << "Total: " << num_count << endl;
    return 0;
}