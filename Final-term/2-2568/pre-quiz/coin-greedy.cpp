#include <iostream>
#include <vector>
using namespace std;

struct Coin {
    int value;
    int count;
    int used;
};

void coinChangeGreedy(int targetAmount, vector<Coin>& coins){
    int totalCoinsUsed = 0;
    for(int i = 0; i < coins.size(); i++){
        if(targetAmount <= 0) break;

        int needCoins = targetAmount / coins[i].value;
        int useCoins = min(needCoins, coins[i].count);

        if(useCoins > 0){
            coins[i].used = useCoins;
            totalCoinsUsed = totalCoinsUsed + useCoins;
            targetAmount = targetAmount - useCoins * coins[i].value;
        }
    }
    if(targetAmount > 0){
        cout << "Impossible" << endl;
    } else {
        cout << totalCoinsUsed << endl;
        for(int i = 0; i < coins.size(); i++){
            if(coins[i].used > 0){
                cout << coins[i].value << ":" << coins[i].used;
            }
            cout << endl;
        }
    }
}

int main (){
    int n; 
    cin >> n;

    vector<Coin> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i].value;
        coins[i].used = 0;
    }

    for(int i = 0; i < n; i++){
        cin >> coins[i].count;
    }

    int targetAmount;
    cin >> targetAmount;

    sort(coins.begin(), coins.end(), [](Coin a, Coin b) {
        return a.value > b.value;
    });

    coinChangeGreedy(targetAmount, coins);

    return 0;
}