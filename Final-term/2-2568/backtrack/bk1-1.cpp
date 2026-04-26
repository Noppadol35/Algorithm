#include<iostream>
using namespace std;

int countPosition = 0;
void permutation(int arr[], int start, int end)
{
    if(start == end){
        int pos1 = -1;
        int pos2 = -1;
        for(int i = 0; i <= end; i++){
            if(arr[i] == 1) pos1 = i;
            if(arr[i] == 2) pos2 = i;
        }
        if(abs(pos1 - pos2) == 1){
            countPosition++;
        }
        return;
    }

    for(int i = start; i <= end; i++){
        swap(arr[start], arr[i]);
        permutation(arr, start + 1, end);
        swap(arr[start], arr[i]);
    }
}

int main(){
    int n;
    cin >> n;

    int arr[20] = {};

    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }

    permutation(arr, 0, n - 1);
    cout << countPosition << endl;

    return 0;
}