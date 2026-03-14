#include <iostream>
#include <vector>
using namespace std;

struct item
{
    double value;
    double weight;
    double truevalue;
};


int main(){
    double capacity;
    int n;

    cin >> n >> capacity;
    vector<item> items(n);
    for(int i = 0; i < n; i++){
        cin >> items[i].weight >> items[i].value;
        items[i].truevalue = items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), [](item a, item b){
        return a.truevalue > b.truevalue;
    });

    cout << "sorted: " << endl;
    for(int i = 0; i < n; i++){
        cout << items[i].weight << " " << items[i].value << " " << items[i].truevalue << endl;
    }

    int totalvalue = 0;
    for(int i = 0; i < n; i++){
        if(capacity >= items[i].weight){
            totalvalue = totalvalue + items[i].value;
            capacity = capacity - items[i].weight;
        } 
        else {
            int cap = (capacity / items[i].weight) * 100;
            totalvalue = totalvalue + (cap * items[i].value / 100);
            break;
        }
        cout << endl;
        cout << items[i].weight << " " << items[i].value << " " << items[i].truevalue << endl;
    }

    cout << "ans:"<< totalvalue << endl;
    return 0;
}