#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[1000];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }


    int sum = 0;
    int max_sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
        } else if(sum > max_sum){
            max_sum = sum;
        }
        
    }
    cout << max_sum << endl;
    return 0;
}