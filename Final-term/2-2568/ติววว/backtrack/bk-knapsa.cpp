#include <iostream>
#include <vector>
using namespace std;

struct item
{
    int weight;
    int value;
};


void kanapsage(vector<item>& items, int capacity, int index, vector<int>& subset, int& goalMaxValue)
{
    if(index == items.size()){
        int currentWeight = 0;
        int currentValue = 0;

        for(int i = 0; i < subset.size(); i++){
            if(subset[i] == 1){
                currentWeight = currentWeight + items[i].weight;
                currentValue = currentValue + items[i].value;
            }
        }

        if(currentWeight <= capacity){
            if(currentValue > goalMaxValue){
                goalMaxValue = currentValue;
            }
        }
        return;
    }
    subset[index] = 0;
    kanapsage(items, capacity, index + 1, subset, goalMaxValue);

    subset[index] = 1;
    kanapsage(items, capacity, index + 1, subset, goalMaxValue);

}
int main (){
    int capacity;
    cin >> capacity;
    
    vector<item> items(4);

    for(int i = 0; i < 4; i++){
        cin >> items[i].weight;
    }
    for(int i = 0; i < 4; i++){
        cin >> items[i].value;
    }

    vector<int> subset(items.size());

    int goalMaxValue = 0;

    kanapsage(items, capacity, 0, subset, goalMaxValue);

    cout << "ans: " << goalMaxValue << endl;
    return 0;

}