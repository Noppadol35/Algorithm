#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n_vertex, n_edge;
    cin >> n_vertex >> n_edge;

    vector<vector<int>> adj_matrix(n_vertex, vector<int>(n_vertex, 0));

    for(int i = 0; i < n_edge; i++){
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
    }
    
    for(int i = 0; i < n_vertex; i++){
        for(int j = 0; j < n_vertex; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}