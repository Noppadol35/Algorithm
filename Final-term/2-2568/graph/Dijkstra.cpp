#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int Dijkstra(vector<vector<pair<int, int>>>& graph, int V, int startVertex, int dst)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inTree(V, false);

    pq.push({0, startVertex});
    dist[startVertex] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        inTree[u] = true;
        pq.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            if (!inTree[v] && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path;
    for(int i = dst; i != -1; i = parent[i]){
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    return dist[dst];
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj_list(n + 1);
    for (int i = 0; i < e; i++)
    {
        int start, destination, weight;
        cin >> start >> destination >> weight;
        adj_list[start].push_back({destination, weight});
    }

    int src, dst;
    cin >> src >> dst;

    int result = Dijkstra(adj_list, n, src, dst);
    cout << result << endl;

    return 0;
}