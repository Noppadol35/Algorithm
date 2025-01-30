#include<bits/stdc++.h>
using namespace std;
int value[5] = {-1,12, 5, 4, 2};
int w[5] = {-1, 8,7,4,2};
int max_w  = 18;
int max_v = -1;

void print_sol(int x[], int n) {
    int sum_w = 0;
    int sum_v = 0;

    for (int i = 1; i <= n; i++) {
        sum_w += w[x[i]];
        sum_v += value[x[i]];
    }
    
    cout << sum_w << "||" << sum_v<< endl ;

    if(sum_w <= max_w){
        max_v = max(sum_v, max_v);
    }
}

void subset2(int x[], int l, int n) {

    print_sol(x, l);

       int j;
    if (l == 0) 
	j = 1; 
    else 
        j = x[l] + 1;

    for (int i = j; i <= n; i++) {
        x[l + 1] = i;
        subset2(x, l + 1, n);
    }
}

int main() {
    int n = 4; 	// Number of elements
    int x[n + 1];	 // Array to store subset

   subset2(x, 0, n);
   cout << max_v;
    return 0;
}
