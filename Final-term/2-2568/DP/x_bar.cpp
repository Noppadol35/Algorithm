#include<iostream>
using namespace std;

int memo_sum = 0;
int memo_n = 0;

float update_x_bar(int new_value) {
    memo_sum += new_value;
    memo_n++;
    return (float)memo_sum / memo_n;
}

int main(){
    int x[5] = {4, 5, 12, 7, 8};
    for(int i = 0; i < 5; i++){
        update_x_bar(x[i]);
    }

    cout << (float)memo_sum / memo_n << endl;

    int x_new = 18;
    float x_bar = update_x_bar(x_new);

    cout << memo_sum / memo_n << endl;
    cout  << memo_sum << " " << memo_n << endl;
    return 0;
}