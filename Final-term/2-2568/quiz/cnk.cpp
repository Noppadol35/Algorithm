#include <iostream>
using namespace std;

int memo[1001][1001];

int Cnk(int n, int k)
{
    if (n < k || k < 0)return 0;
    if (k == 0)return n;
    if (k == n)return n * n;
    if (memo[n][k] != 0)return memo[n][k];

    return memo[n][k] = Cnk(n - 1, k - 1) + Cnk(n - 1, k);
}

int main()
{
    int s;
    cin >> s;

    int sumCnk = 0;
    if (s >= 1 && s <= 1000)
    {
        for (int k = 0; k <= s; k++){
            sumCnk = sumCnk + Cnk(s - k, k);
        }
        cout << sumCnk << endl;
    }
}