#include <iostream>
#include <vector>

using namespace std;

#define inf 500000
#define FALSE -1
#define TRUE 1

// 1. Pass the dynamic size 'V' and use const references for vectors
int minDistance(const vector<int>& dist, const vector<int>& inTree, int V){
    int min = inf, min_index = -1;

    for(int v = 0; v < V; v++){
        if(inTree[v] == FALSE && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// 2. Accept a 2D vector instead of a C-style array
void Dijkstra(const vector<vector<int>>& graph, int src){
    int V = graph.size(); // Extract the exact number of vertices dynamically
    
    // 3. Use vectors for internal state to match the dynamic size
    vector<int> dist(V, inf);
    vector<int> inTree(V, FALSE);
    vector<int> parent(V, -1);

    dist[src] = 0;
    
    for(int i = 0; i < V - 1; i++){
        int u = minDistance(dist, inTree, V);
        
        // Safety check: if u is -1, the remaining vertices are unreachable
        if (u == -1) break; 

        inTree[u] = TRUE;
        
        for(int v = 0; v < V; v++){
            // Added graph[u][v] != inf to prevent integer overflow when adding
            if(inTree[v] == FALSE && graph[u][v] != inf && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Optional: Print the results to verify it works
    cout << "\nVertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main(){
    int n_vertex, n_edge;
    cout << "Enter number of vertices and edges: ";
    cin >> n_vertex >> n_edge;

    // Creates an n_vertex by n_vertex matrix initialized to 'inf'
    vector<vector<int>> adj_matrix(n_vertex, vector<int>(n_vertex, inf));

    cout << "Enter edges (u v weight):" << endl;
    for(int i = 0; i < n_edge; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_matrix[u][v] = w; 
    }

    Dijkstra(adj_matrix, 0);
    return 0;
}