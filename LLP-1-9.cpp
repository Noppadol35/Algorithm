#include <iostream>
using namespace std;

int countSetBits(int n)
{
    if (n == 0)
        return 0;
    return (n & 1) + countSetBits(n >> 1);
}

int main()
{
    int n;
    cin >> n;

    if (n < 0 || n > 10000)
    {
        return 1;
    }

    cout << countSetBits(n) << endl;

    return 0;
}
