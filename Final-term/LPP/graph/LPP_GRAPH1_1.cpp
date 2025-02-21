#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void BFS(vector<vector<int> > &graph, int startVertex, int v, int goal) {
    vector<bool> visited(v, false);  
    vector<int> distance(v, -1); 
    
    queue<int> queue;
    queue.push(startVertex);
    visited[startVertex] = true;
    distance[startVertex] = 0;  

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        for (int i = 0; i < v; ++i) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                queue.push(i);
                visited[i] = true;
                distance[i] = distance[currentVertex] + 1;  
            }
        }
    }
    
    cout << distance[goal] << endl;  
}

int main() {
    int n; 
    cin >> n;

    vector<vector<int> > graph(n, vector<int>(n, 0)); 

    int x, s, j;
    for (int i = 0; i < n; i++) {  
        while (true) {
            cin >> x;
            if (x == 0) break;  
            graph[i][x - 1] = 1;  
        }
    }

    cin >> s >> j;  
    BFS(graph, s - 1, n, j - 1);  

    return 0;
}

