#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printGraph(vector<vector<int> >& graph){
    for(int i = 0; i < graph.size(); i++){
        cout << i << ": ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << " " << graph[i][j];
        }
        cout << endl; 
    }
}

int main() {
    int n_vertex = 6; 
    
    vector<vector<int> > graph(n_vertex, vector<int>(n_vertex, 0));
    
    int numVertices = graph.size();

    graph[0][1] = 1; graph[0][2] = 1;
    graph[1][0] = 1; graph[1][3] = 1;
    graph[2][0] = 1; graph[2][3] = 1;
    graph[3][1] = 1; graph[3][2] = 1; graph[3][4] = 1;
    graph[4][3] = 1; graph[4][5] = 1;
    graph[5][4] = 1;

    printGraph(graph);

    return 0;
}

