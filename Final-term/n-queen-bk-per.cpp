#include <iostream>
#include <cmath>
using namespace std;

int num_count = 0;

int isSafe(int x[], int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(j - i) == abs(x[j] - x[i]) || (x[i] == x[j]))
            {
                return 0;
            }
        }
    }
    return 1;
}

void permute(int x[], int start, int end){
    
    num_count++;
    if(start == end){
        cout << "ans: ";
        for (int i = 0; i < end; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = start; i < end; i++){
        swap(x[start], x[i]);
        if(isSafe(x, start + 1)){
            permute(x, start + 1, end);
        }
        swap(x[start], x[i]);
    }
}


int main () {
    int x[] = {0, 1, 2, 3};
    permute(x, 0, 4);
    cout << "Total: " << num_count << endl;
    return 0;
}