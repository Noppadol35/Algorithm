#include<iostream>
using namespace std;

// GCD
long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// LCM ครน
long long lcm(long long a, long long b){
    if(a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}


long long findGCD_DC(int arr[], int l, int r){
    if(l == r){
        return arr[l];
    }

    int mid = l + (r - l) / 2;
    long long leftFindGcd = findGCD_DC(arr, l, mid);
    long long rightFindGcd = findGCD_DC(arr, mid + 1, r);

    return gcd(leftFindGcd, rightFindGcd);
}

long long findSum_DC(int arr[], int l, int r){
    if(l == r){
        return arr[l];
    }

    int mid = l + (r - l) / 2;
    long long leftFindSum = findSum_DC(arr, l, mid);
    long long rightFindSum = findSum_DC(arr, mid + 1, r);

    return leftFindSum + rightFindSum;
}


int main(){
    int n = 0;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long resultGcd = findGCD_DC(arr, 0, n-1);
    long long resultSum = findSum_DC(arr, 0, n-1);
    long long avgSum = resultSum / n;

    long long ansTotal = gcd(resultGcd, avgSum);

    cout << resultGcd << " " << avgSum << " " << ansTotal;
}