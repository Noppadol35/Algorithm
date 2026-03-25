#include<iostream>
#include<vector>
using namespace std;

struct itemValue
{
    int value1;
    int value2;
};

int twinsDiffValue(vector<itemValue>& items, int n){
    vector<int> diff;
    for(int i = 0; i < n; i++){
        diff.push_back(abs(items[i].value1 - items[i].value2));
    }

    sort(diff.begin(), diff.end(), greater<int>());

    int currentDiff = 0;
    for(int i = 0; i < n; i++){
        currentDiff = abs(currentDiff - diff[i]);
    }
    return currentDiff;
}

int main(){
    int n;
    cin >> n;

    vector<itemValue> items(n);
    for(int i = 0; i < n; i++){
        cin >> items[i].value1 >> items[i].value2;
    }
    
    cout << twinsDiffValue(items, n) << endl;
    return 0;
}
