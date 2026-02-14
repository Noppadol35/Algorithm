#include <iostream>
#include <cmath>
using namespace std;

int n = 4, x[4];
int num_count = 0;

void n_queen(int k)
{
    if (k == n)
    {
        int flag = 0;
        for (int i = 1; i < k; i++)
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
        for(int i = 0; i < k; i++){
            cout << x[i] << " ";
        }
        cout << endl;
        
        if (flag == 0)
        {
            cout << "ans: ";
            for (int i = 0; i < k; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
    } else {
        for(int row = 0; row < n; row++) {
            x[k] = row;
            n_queen(k + 1);
        }
    }
    
}

int main()
{
    n_queen(0);

    cout << "Total: " << num_count << endl;
    return 0;
}