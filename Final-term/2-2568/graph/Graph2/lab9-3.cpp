#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

int maxDistanceWithNewHospital(int n,const vector<vector<pair<int, int>>> &roads,const vector<int> &oldHospitals,int newHospital){
    vector<int> dist(n + 1, INF);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    for (int i = 0; i < oldHospitals.size(); i++)
    {
        dist[oldHospitals[i]] = 0;
        pq.push({0, oldHospitals[i]});
    }

    dist[newHospital] = 0;
    pq.push({0, newHospital});
    
    while (!pq.empty())
    {

        int currentDist = pq.top().first;
        int area = pq.top().second;
        pq.pop();

        if (currentDist > dist[area])
            continue;

        for (int i = 0; i < roads[area].size(); i++)
        {
            int nextArea = roads[area][i].first;
            int length = roads[area][i].second;

            if (dist[area] + length < dist[nextArea])
            {
                dist[nextArea] = dist[area] + length;
                pq.push({dist[nextArea], nextArea});
            }
        }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; i++)
        maxDist = max(maxDist, dist[i]);

    return maxDist;
}

int main()
{

    int f, n; 
    cin >> f >> n;

    vector<int> hospitals(f);
    vector<bool> hasHospital(n + 1, false);

    for (int i = 0; i < f; i++)
    {
        cin >> hospitals[i];
        hasHospital[hospitals[i]] = true;
    }
        
    vector<vector<pair<int, int>>> roads(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        roads[x].push_back({y, r});
        roads[y].push_back({x, r});
    }

    int bestLocation = 1;  
    int bestMaxDist = INF;

    for (int candidate = 1; candidate <= n; candidate++)
    {

        if (hasHospital[candidate])
            continue;

        int currentMaxDist = maxDistanceWithNewHospital(n, roads, hospitals, candidate);

        if (currentMaxDist < bestMaxDist)
        {
            bestMaxDist = currentMaxDist;
            bestLocation = candidate;
        }
    }

    cout << bestLocation << endl;

    return 0;
}