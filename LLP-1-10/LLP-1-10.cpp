#include <iostream>
using namespace std;

const int n = 100000; 

int main()
{
    
    int N = 0;
    cin >> N;

    int C[n+2] = {0};

    for (int i = 0; i < N; i++)
    {
        int A, B = 0;
        cin >> A >> B;
        C[A]++;     // start
        C[B + 1]--; // end
    }

    int max_C = 0;
    int line_C = 0;
    int start = 0;
    int end = 0;

    for (int i = 0; i <= n; i++)
    {
        line_C += C[i];
        if (line_C > max_C)
        {
            max_C = line_C;
            start = i;
            end = i;
        }
        else if (line_C == max_C)
        {
            end = i;
        }
    }

    cout << start << " " << end << " " << max_C << endl;

    return 0;
}
