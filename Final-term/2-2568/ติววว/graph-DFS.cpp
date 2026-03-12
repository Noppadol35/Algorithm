#include <iostream>
#include <vector>
#include <queue>
using namespace std;



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
            if()
        }
    }

    return 0;
}