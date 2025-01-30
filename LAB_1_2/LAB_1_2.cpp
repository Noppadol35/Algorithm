#include <iostream>
using namespace std;
#define MAX 1000000

int main()
{
    int num;
    cin >> num;

    if (num <= 0 || num > MAX) {
        return 1; 
    }

    int A[num];
    int freq[MAX] = {0};

    for (int i = 0; i < num; i++)
    {
        cin >> A[i];

        if (A[i] < 0 || A[i] >= MAX) {
            return 1;
        }

        freq[A[i]]++;
    }

    int max_freq = 0, min_freq = num;

    for (int i = 0; i < MAX; i++) 
    {
        if (freq[i] > 0)
        {
            if (freq[i] > max_freq)
                max_freq = freq[i];
            if (freq[i] < min_freq)
                min_freq = freq[i];
        }
    }

    cout << (max_freq - min_freq) << endl;

    return 0;
}
