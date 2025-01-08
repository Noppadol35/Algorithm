#include <iostream>
using namespace std;

int main()
{
    int num;

    cin >> num;

    int A[num];
    int freq[1000000] = {0};

    for (int i = 0; i < num; i++)
    {
        cin >> A[i];
        freq[A[i]]++;
    }

    int max_freq = 0, min_freq = num;

    for (int i = 0; i < num; i++)
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
