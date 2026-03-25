#include<iostream>
#include<vector>

using namespace std;

struct timeAndDeparture
{
    double arrival;
    double departure;
};

int trainMinPlatforms(vector<timeAndDeparture>& trains, int n){
    vector<double> arrivalTimes, departureTimes;
    for(int i = 0; i < n; i++){
        arrivalTimes.push_back(trains[i].arrival);
        departureTimes.push_back(trains[i].departure);
    }
    sort(arrivalTimes.begin(), arrivalTimes.end());
    sort(departureTimes.begin(), departureTimes.end());

    int platforms = 0, minPlatforms = 0;
    int i = 0, j = 0;
    while(i < n && j < n){
        if(arrivalTimes[i] < departureTimes[j]){
            platforms++;
            minPlatforms = max(minPlatforms, platforms);
            i++;
        }
        else{
            platforms--;
            j++;
        }
    }
    return minPlatforms;
}

int main(){
    int n;
    cin >> n;

    vector<timeAndDeparture> trains(n);
    for(int i = 0; i < n; i++){
        cin >> trains[i].arrival >> trains[i].departure;
    }

    cout << trainMinPlatforms(trains, n) << endl;
    return 0;
}