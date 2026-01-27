#include<iostream>
using namespace std;
    

int findmax(int arr[], int l, int r){
    if(l == r){
        return arr[l];
    }
    int mid = l + (r-l) / 2;

    if(findmax(arr, l, mid) > findmax(arr, mid+1, r)){
        return findmax(arr, l, mid);
    } else {
        return findmax(arr, mid+1, r);
    }

}

int main(){
    int arr[] = {5,4,50,1,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << findmax(arr, 0, n-1);

    return 0;
}
