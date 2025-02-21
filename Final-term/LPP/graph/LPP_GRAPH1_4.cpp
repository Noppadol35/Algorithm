#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void BFS(vector<vector<int> > &graph, int startVertex, int v, int m) {  
    vector<int> distance(v, -1);  
    
    queue<int> queue;
    queue.push(startVertex);
    distance[startVertex] = 0;  

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        for (int i = 0; i < v; i++) {
            if (graph[currentVertex][i] == 1 && distance[i] == -1) {  
                distance[i] = distance[currentVertex] + 1;
                if (distance[i] <= m) { 
                    queue.push(i);  
                }
            }
        }
    }
    
    int uncover = 0;  
    for (int i = 0; i < v; i++) {
        if (distance[i] == -1 || distance[i] > m) {  
            uncover++;
        }
    }
    
    cout << uncover << endl; 
}

int main() {
    int n; 
    cin >> n;  

    vector<vector<int> > graph(n, vector<int>(n, 0));  

    int p, q;
    while (true) { 
        cin >> p >> q;
        if (p == 0 && q == 0) break;  
        graph[p-1][q-1] = 1; 
    }

    int k, m;
    cin >> k >> m;  
    
    BFS(graph, k - 1, n, m);  

    return 0;
}

