#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9

struct Coin {
    int value;
    int count;
};

int coinChange(int targetAmount, int index, vector<Coin>& coins, vector<vector<int>>& memo, vector<vector<int>>& choice){
    if(targetAmount == 0) return 0;
    if(index == coins.size()) return INF;

    if(memo[targetAmount][index] != -1) return memo[targetAmount][index];

    int minCoins = INF;
    int bastSelectedCount = 0;
    for(int i = 0; i <= coins[index].count; i++){
        int useValue = i * coins[index].value;
        if(useValue > targetAmount) break;

        int coinsNeeded = coinChange(targetAmount - useValue, index + 1, coins, memo, choice);
        if(coinsNeeded != INF && coinsNeeded + i < minCoins){
            minCoins = coinsNeeded + i;
            bastSelectedCount = i;
        }
    }
    choice[targetAmount][index] = bastSelectedCount;
    return memo[targetAmount][index] = minCoins;
}

int main (){
    int n;
    cin >> n;

    vector<Coin> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i].value;
    }

    for(int i = 0; i < n; i++){
        cin >> coins[i].count;
    }

    int targetAmount;
    cin >> targetAmount;

    sort(coins.begin(), coins.end(), [](Coin a, Coin b){
        return a.value > b.value;
    });

    vector<vector <int>> memo(targetAmount + 1, vector<int>(n, -1));
    vector<vector <int>> choice(targetAmount + 1, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }

    int result = coinChange(targetAmount, 0, coins, memo, choice);

    if(result == INF){
        cout << "Impossible" << endl;
    } else {
        cout << result << endl;
        for(int i = 0; i < n; i++){
            cout << coins[i].value << ":" << choice[targetAmount][i] << endl;
            targetAmount = targetAmount - (choice[targetAmount][i] * coins[i].value);
        }
    }
    return 0;
}

