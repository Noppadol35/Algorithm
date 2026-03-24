#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int Dijkstra(vector<vector<pair<int, int>>> &adj, int V, int src, int dst)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        if(dist[u] < current_dist) continue;
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[dst] == INF) return -1;
    return dist[dst];
}

int main()
{
    int n;
    cin >> n;
    int node, lan, src, dst;

    while(n--)
    {
        cin >> node >> lan >> src >> dst;
        vector<vector<pair<int, int>>> adj_list(node + 1);

        for (int i = 0; i < lan; i++)
        {
            int start, distination, bandwidth;
            cin >> start >> distination >> bandwidth;
            adj_list[start].push_back({distination, bandwidth});
            adj_list[distination].push_back({start, bandwidth});
        }
        
        int result =Dijkstra(adj_list, node + 1, src, dst);
        cout << result << endl;
    }

    return 0;
}