#include<iostream>
using namespace std;

int maxArr(int arr[] , int l , int r , int &count){
    count = count + 1; 

    // Base Case: เหลือตัวเดียว คืนค่านั้นกลับไปเลย
    if(l == r){
        return arr[l];
    }
    int m = (l+r) / 2;

    int max_left = maxArr(arr, l, m, count); 
    int max_right = maxArr(arr, m + 1, r, count); 

    if(max_left > max_right){
        return max_left;
    } else {
        return max_right;
    }
}

int main(){
    int n = 10;
    int arr[] = {60,70,60,60,70,70,70,70,50,60};
    int count = 0;
    
    cout << "Max Value: " << maxArr(arr , 0 , n-1, count) << endl;
    cout << "Function Calls: " << count << endl;
}