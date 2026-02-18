#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> graph, int start, vector<bool>& visited){
    visited[start] = true;
    cout << start << " ";
    for(int i = 0; i < graph[start].size(); i++){
        if(graph[start][i] == 1 && !visited[i]){
            DFS(graph, i, visited);
        }
    }
    
}

int main(){
    int n_vertex, n_edge;
    cin >> n_vertex >> n_edge;

    vector<vector<int>> adj_matrix(n_vertex, vector<int>(n_vertex, 0));
    for(int i = 0; i < n_edge; i++){
        int start, distination;
        cin >> start >> distination;
        adj_matrix[start][distination] = 1;
        adj_matrix[distination][start] = 1;
    
        
    }

    for(int i = 0; i < n_vertex; i++){
        for(int j = 0; j < n_vertex; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << adj_matrix.size() << endl;

    cout << endl;

    vector<bool> visited(n_vertex, false);
    DFS(adj_matrix, 3, visited);
}