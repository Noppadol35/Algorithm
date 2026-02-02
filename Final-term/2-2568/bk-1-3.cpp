#include <iostream>
#include <cmath>
using namespace std;

int max_value = 0;
int k;
int n = 4;
int value[10];
int weight[10];

void knapsack(int index, int curent_w, int curent_v)
{
    if (index == n)
    {
        if (curent_v > max_value)
        {
            max_value = curent_v;
        }
        return;
    }

    // not take
    knapsack(index + 1, curent_w, curent_v);

    // take
    if (curent_w + weight[index] <= k)
    {
        knapsack(index + 1, curent_w + weight[index], curent_v + value[index]);
    }
}

int main()
{
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    knapsack(0, 0, 0);

    cout << max_value << endl;
    return 0;
}