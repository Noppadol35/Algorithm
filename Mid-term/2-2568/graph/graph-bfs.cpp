#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> graph, int startVertex, int V){
    vector<bool> visited(V, false);
    queue<int> queue;
    queue.push(startVertex);
    visited[startVertex] = true;

    while(!queue.empty()){
        int CurentVertex = queue.front();
        queue.pop();
        cout << CurentVertex << " ";

        for(int i = 0; i < graph[CurentVertex].size(); i++){
            if(graph[CurentVertex][i] && !visited[i]){
                queue.push(i);
                visited[i] = true;
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

    cout << graph_list[2][0] << " " << graph_list[2][1] << endl;
    // for(int i = 0; i < n_vertex; i++){
    //     cout << i << ": ";
    //     for(int j = 0; j < graph_list[i].size(); j++){
    //         cout << graph_list[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // BFS(graph_list, 2, n_vertex);
}