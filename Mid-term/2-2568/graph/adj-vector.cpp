#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n_vertex, n_edge;
    cin >> n_vertex >> n_edge;

    vector<vector<int>> adj_list(n_vertex);
    for(int i = 0; i < n_edge; i++){
        int start, distination;
        cin >> start >> distination;
        adj_list[start].push_back(distination);
    }
    
    cout << endl;
    for(int i = 0; i < n_vertex; i++){
        cout << i << ": ";
        for(int j = 0; j < adj_list[i].size(); j++){
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
}