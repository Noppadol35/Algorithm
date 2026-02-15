#include <iostream>
using namespace std;

int countRecursive = 0;

void mergeSortFunction(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    int i = 0,j = 0,k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    countRecursive++;
    if (l < r){
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        mergeSortFunction(arr, l, mid, r);
    }
}

int findmax(int arr[], int l, int r)
{
    if (l == r){
        return arr[l];
    }
    int mid = l + (r - l) / 2;

    if (findmax(arr, l, mid) > findmax(arr, mid + 1, r)){
        return findmax(arr, l, mid);
    }
    else{
        return findmax(arr, mid + 1, r);
    }
}

int main()
{
    int n = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    int findmax = arr[0];
    int countFindMax = 0;

    int currentVal = arr[0];
    int countVal = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] == currentVal){
            countVal++;
        }
        else{
            if (countVal > countFindMax){
                findmax = currentVal;
                countFindMax = countVal;
            }

            currentVal = arr[i];
            countVal = 1;
        }
    }

    if (currentVal > findmax){
        findmax = currentVal;
        countFindMax = countVal;
    }

    cout << findmax << " " << countFindMax << " " << countRecursive;

    return 0;
}