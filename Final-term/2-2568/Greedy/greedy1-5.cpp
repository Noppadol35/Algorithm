#include<iostream>
#include<vector>

using namespace std;

struct dist
{
    int start;
    int destination;
};

void sumLine(vector<dist>& dists, int n, int xa, int xb){
    vector<dist> selectLine;
    int bestPath = 0;
    int currentStart = xa;
    int i = 0;

    while(i < n && currentStart < xb){
        int bestDestination = currentStart;
        int index = -1;
        for(int i = 0; i < n; i++){
            if(dists[i].start <= currentStart && dists[i].destination > bestDestination){
                bestDestination = dists[i].destination;
                index = i;
            }
        }
        if(bestDestination == currentStart){
            cout << -1 << endl;
            return;
        }
        selectLine.push_back(dists[index]);
        currentStart = bestDestination;
    }
    cout << selectLine.size() << endl;
    for(int i = 0; i < selectLine.size(); i++){
        cout << selectLine[i].start << " " << selectLine[i].destination << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<dist> distance(n);
    for(int i = 0; i < n; i++){
        cin >> distance[i].start >> distance[i].destination;
    }

    sort(distance.begin(), distance.end(), [](dist a, dist b){
        return a.start < b.start;
    });

    int xa, xb;
    cin >> xa >> xb;
    sumLine(distance, n, xa, xb);
    return 0;
}