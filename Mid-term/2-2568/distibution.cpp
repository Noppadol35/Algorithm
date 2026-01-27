#include <iostream>
using namespace std;

void distribution(int arr[], int n, int max, int min) {
    int range = max - min + 1;
    int D[range];
    for (int i = 0; i < range; i++) {
        D[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        D[arr[i] - min]++;
    }

    for(int j = 1; j < range; j++) {
        D[j] += D[j - 1];
    }

    int s[n];
    for(int i = n - 1; i >= 0; i--) {
        int index = arr[i] - min;
        s[D[index] - 1] = arr[i];
        D[index]--;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = s[i];
    }
}
int main() {
    int arr[] = {16, 25, 2, 54, 36, 9, 12, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    distribution(arr, n, max, min);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}