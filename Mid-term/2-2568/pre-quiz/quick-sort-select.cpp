#include<iostream>
using namespace std;

int Partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void Quick_sort(int arr[], int l, int r){
    if (l < r){
        int p = Partition(arr, l, r);
        Quick_sort(arr, l, p - 1);
        Quick_sort(arr, p + 1, r);
    }
}

int quickSelect(int arr[], int l, int r, int k)
{
    if (l == r)
    {
        return arr[l];
    }
    int p = partition(arr, l, r);
    if (k == p)
    {
        return arr[p];
    }
    if (k < p)
    {
        return quickSelect(arr, l, p - 1, k);
    }
    else
    {
        return quickSelect(arr, p + 1, r, k);
    }
}

int main(){
    int arr[] = {}
    return 0;
}