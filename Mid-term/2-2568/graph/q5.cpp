#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> graph, int u, int dest, int visited[], vector<int>& path){
    vector<bool> visited_bool(graph.size(), false);
    queue<int> queue;
    queue.push(u);
    visited_bool[u] = true;

    if(u == dest){
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << " ";
        }
    } else {
        for(int i = 0; i < graph.size(); i++){
            
        }
    }

    while(!queue.empty()){
        int CurentVertex = queue.front();
        queue.pop();
        cout << CurentVertex << " ";
        path.push_back(CurentVertex);

        for(int i = 0; i < graph[CurentVertex].size(); i++){
            int neighbor = graph[CurentVertex][i];
            if(!visited_bool[neighbor]){
                queue.push(neighbor);
                visited_bool[neighbor] = true;
            }
        }
    }
}

int main(){
    int n_vertex, n_edge;
    cin >> n_vertex >> n_edge;

    vector<vector<int>> graph_list(n_vertex);
    for(int i = 0; i < n_edge; i++){
        int start, distination;
        cin >> start >> distination;
        graph_list[start].push_back(distination);
    }

    cout << endl;
    for(int i = 0; i < n_vertex; i++){
        cout << i << ": ";
        for(int j = 0; j < graph_list[i].size(); j++){
            cout << graph_list[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> path;
    BFS(graph_list, 2, n_vertex, path);
    cout << endl;
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
}