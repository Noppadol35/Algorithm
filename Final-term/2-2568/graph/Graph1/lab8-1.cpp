#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int BFS(vector<vector<int>>& graph, int startVertex, int destVertex, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(startVertex);
    dist[startVertex] = 0;

    while(!q.empty()){
        int currentVertex = q.front();
        q.pop();
        if(currentVertex == destVertex) return dist[currentVertex];
        
        for(int i = 0; i < graph[currentVertex].size(); i++){
            int neighbor = graph[currentVertex][i];
            if(dist[neighbor] == -1){
                dist[neighbor] = dist[currentVertex] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;

        int q;
        cin >> q;
        while(q != 0){
            graph[p].push_back(q);
            graph[q].push_back(p);
            cin >> q;
        }
    }

    int s, d;

    cin >> s >> d;

    int shotestPath = BFS(graph, s, d, n);
    cout << shotestPath << endl;
    return 0;
}