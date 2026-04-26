#include <iostream>
using namespace std;

int a[] = {25, 10, 9, 2, 1};
int k = 12;
int num_count = 0;
void print_sol(int x[], int n){
    for(int j = 1; j <= n; j++){
        cout << x[j] << ": ";
        if(x[j] == 1){
            cout << a[j] << " ";
        }
        
    }
    cout << endl;
}

void subset1(int x[], int l, int r){
    
    // if(sum == k){
    //     print_sol(x, r);
    //     return;
    // }
    if(l == r){
        print_sol(x, r);
        return;
    }
    else {
        x[l + 1] = 1;
        //sum = sum + a[l];
        subset1(x, l+1, r);
        x[l + 1] = 0;
        //sum = sum - a[l];
        subset1(x, l+1, r);
        num_count++;
    }


}

int main() {
    int n = 4;
    int x[n+1];
    subset1(x, 0, n);
    //cout << "Total: " << num_count << endl;
    return 0;
}