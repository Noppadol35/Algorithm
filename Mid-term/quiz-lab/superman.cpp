#include<iostream>
using namespace std;

long long calculateSumation(long long n){
    return (n*(n + 1)) / 2;
}


long long recuresiveBinaryFunction(long long low, long long high, long long target){
    if(high < low){
        return 0;
    } 
    long long mid = low + (high - low) / 2;
    long long curentMid = calculateSumation(mid);

    if(curentMid == target){
        return mid;
    } else if (curentMid > target) {
        return recuresiveBinaryFunction(low, mid-1, target);
    } else {
        return recuresiveBinaryFunction(mid + 1, high, target);
    }

}
int main(){
    long long target;
    cin >> target;
    long long result = recuresiveBinaryFunction(1, 100100100100100, target);
    cout << result;
    return 0;
}

// logn long int target;
    // cin >> target;
    // int sum_temp = 0;
    // int sum = 0;
    // int i =0;
    // while(sum_temp != target){
    //     sum++;
    //     sum_temp += sum;
    //     i++;
    // }
    // cout << sum_temp;
    // cout << endl;
    // cout << i;