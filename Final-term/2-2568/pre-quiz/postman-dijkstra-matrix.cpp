#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int Dijkstra(const vector<vector<int>>& graph, int V, int src, int dest){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(V, INF);
    vector<int> parent(V, -1);
    vector<bool> intree(V, false);

    pq.push({0, src});
    distance[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(int v = 0; v < V; v++){
            
            if(graph[u][v] != INF && !intree[v]){
                int weight = graph[u][v];
                if(distance[u] + weight < distance[v]){
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                    parent[v] = u;
                }
            }
        }
    }
    return distance[dest]; 
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; 
    }

    int result = Dijkstra(graph, n + 1, s, t);
    cout << result << endl;

    return 0;
}