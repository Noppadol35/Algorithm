#include<bits/stdc++.h>
using namespace std;
int value[5] = {-1,12, 5, 4, 2};
int w[5] = {-1, 8,7,4,2};
int max_w  = 18;
int max_v = -99;

void print_sol(int x[], int n) {
   int sum_w = 0;
   int sum_v = 0;
   
   for(int i = 1; i <= n; i ++){
       cout << x[i] << " " ;
      if(x[i] == 1){
          sum_w += w[i];
          sum_v += value[i];
      }
   }
   cout  << endl;
   
   if(sum_w <= max_w){
       max_v = max(sum_v, max_v);
   }
}

void subset1(int x[], int l, int r) {
    if (l == r) {
        print_sol(x, r);
    } else {
        x[l + 1] = 1;
        subset1(x, l + 1, r);
        x[l + 1] = 0;
        subset1(x, l + 1, r);
    }
}

int main() {
    int n = 4;            // Number of elements
    int x[n + 1];        // Array to store subset

    subset1(x, 0, n);
    cout << max_v;
    return 0;
}
