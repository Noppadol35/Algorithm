#include <iostream>
#include <cmath>
using namespace std;

int num_count = 0;
void permute(int x[], int start, int end){
    
    if(start == end){
        int flag = 0;
        for (int i = 1; i < end; i++)
        {
            
            for (int j = 0; j < i; j++)
            {
                if (abs(j - i) == abs(x[j] - x[i]) || (x[i] == x[j]))
                {
                    flag = 1;
                }
            }
        }
        num_count++;
        for(int i = 0; i < end; i++){
            cout << x[i] << " ";
        }
        
        cout << endl;
        if (flag == 0)
        {
            cout << "ans: ";
            for (int i = 0; i < end; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
    }
    for(int i = start; i < end; i++){
        swap(x[start], x[i]);
        permute(x, start + 1, end);
        swap(x[start], x[i]);
    }
}


int main () {
    int x[] = {0, 1, 2, 3};
    permute(x, 0, 4);
    cout << "Total: " << num_count << endl;
    return 0;
}