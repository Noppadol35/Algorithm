#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> graph, int start, int V){
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";
        for(int i = 0; i < graph[currentVertex].size(); i++){
            int neighbor = graph[currentVertex][i];
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix (n, vector<int> ());
    for(int i = 0; i < m; i++){
        int s, d;
        cin >> s >> d;
        matrix[s].push_back(d);
    }

    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    BFS(matrix, 0, n);

    return 0;
}

===========================================================

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int> (n, 0));

    for(int i = 0; i < m; i++){
        int s, d;
        cin >> s >> d;
        matrix[s][d] = 1;
    }

    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(2);
    visited[2] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout << current << " ";

        for(int i = 0; i < n ; i++){
            int neighbor = matrix[current][i];
            if(neighbor == 1){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    return 0;
}