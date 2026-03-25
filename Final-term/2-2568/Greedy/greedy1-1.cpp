#include<iostream>
#include<vector>

using namespace std;

struct items{
    int id;
    double weight;
    double value;
    double fraction;
};

double fractKanpsack(vector<items>& item, int n, double W){
    vector<double> ratio(n);
    for(int i = 0; i < n; i++){
        ratio[i] = item[i].value / item[i].weight;
        item[i].fraction = 0.0;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(ratio[j] < ratio[j+1]){
                swap(ratio[j], ratio[j+1]);
                swap(item[j], item[j+1]);
            }
        }
    }

    double totalValue = 0;
    for(int i = 0; i < n; i++){
        if(item[i].weight <= W){
            totalValue = item[i].value + totalValue;
            W =  W - item[i].weight;
            item[i].fraction = 1.0;
        }
        else{
            double currentWeight = W / item[i].weight;
            totalValue = totalValue + (currentWeight * item[i].value);
            item[i].fraction = W / item[i].weight;
            break;
        }
    }
    return totalValue;
}

int main(){

    int n;
    double W;
    cin >> n >> W;

    vector<items> item(n);
    for(int i = 0; i < n; i++){
        cin >> item[i].weight;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].value;
    }
    
    double result = fractKanpsack(item, n, W);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(item[j].id > item[j+1].id){
                swap(item[j], item[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << item[i].fraction << " ";
    }
    cout << endl;

    cout << result << endl;


    return 0;
}