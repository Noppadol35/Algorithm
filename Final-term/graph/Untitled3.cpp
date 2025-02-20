#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int> > graph, int startVertex, vector<bool>& visited){
	cout << startVertex << " ";
	visited[startVertex] = true;
	
	for(int i = 0; i < graph.size(); i++){
		if(graph[startVertex][i] & !visited[i]){
			DFS(graph, i, visited);
		}
	}
}

int main(){
	vector<vector<int> > graph(6, vector<int>(6, 0));
    
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[4][5] = graph[5][4] = 1;
    
    
	int v = 6;
	int startVertex = 2;
	
	vector<bool> visited(v, false);
	DFS(graph, startVertex, visited);
	
	return 0;
}
