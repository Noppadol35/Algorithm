#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void printGraph(vector<int> adjList[], int n){
	for(int i = 0; i < n; i++){
        cout << i + 1 << ": ";
        for(int j = 0; j < adjList[i].size(); j++){
            cout << adjList[i][j] << " ";
        }
        cout << endl; 
    }
}
int main(){
	int _node; //5
	int n_edge ; //6
	cin >> _node >> n_edge;
	
	
	vector<int> adjList[_node + 1]; //[6] 012345
	
	int x, y; //1 2
	
	for(int i = 0; i < n_edge; i++){
		cin >> x >> y;
		adjList[ x - 1].push_back(y); 
		//0 -> 2
		//0 -> 2
	 	//cout << i << " ";
	}
	printGraph(adjList, _node);
}
