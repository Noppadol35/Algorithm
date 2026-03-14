#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

int Dijkstra(vector<vector<pair<int, int>>> graph, int V, int src, int dest){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(V, INF);
    vector<int> parent(V, -1);
    vector<bool> intree(V, false);

    pq.push({0, src});
    distance[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(int j = 0; j < graph[u].size(); j++){
            int v = graph[u][j].first;
            int weight = graph[u][j].second;

            if(intree[v] == false && distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
                parent[v] = u;
            }
        }
    }

    //show distance
    for(int i = 0; i < V; i++){
        cout << "Distance from " << src << " to " << i << ": " << distance[i] << endl;
    }

    //show parent
    for(int i = 0; i < V; i++){
        cout << "Parent of " << i << ": " << parent[i] << endl;
    }

    //show path
    vector<int> path;
    for(int v = dest; v != -1; v = parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for(int v = 0; v < path.size(); v++){
        cout << path[v] << " ";
    }
    cout << endl;

    return distance[dest];
}

int main(){
    //n จำนวนเมือง, m จำนวนถนน, s เมืองต้นทาง, t เมืองปลายทาง
    int n,m,s,t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int result = Dijkstra(graph, n + 1, s, t);

    cout << result << endl;
}