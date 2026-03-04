#include <iostream>
using namespace std;

long long gn(int n) {
    
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    return gn(n - 1) + gn(n - 2) - gn(n - 3);
}

int main() {
    
    cout << gn(10) << endl;
    return 0;
}