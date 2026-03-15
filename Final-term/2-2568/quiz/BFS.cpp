#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int BFS(const vector<vector<int>> &graph, int V, int start, int m) {
    vector<int> dist(V + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (dist[current] == m)
            continue;

        for (int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }

    int countUncovered = 0;
    for (int i = 1; i <= V; i++) {
        if (dist[i] == -1 || dist[i] > m) { 
            countUncovered++;
        }
    }

    return countUncovered;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V + 1);

    while (true) {
        int p, q;
        cin >> p >> q;

        if (p == 0 && q == 0)break;

        graph[p].push_back(q);
    }

    int N;
    int k, m;
    cin >> N;

    vector<int> results;
    for(int i = 0; i < N; i++) {
        cin >> k >> m;
        results.push_back(BFS(graph, V, k, m));
    }
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }

    return 0;
}