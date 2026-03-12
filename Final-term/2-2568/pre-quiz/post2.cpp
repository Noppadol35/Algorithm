#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> grid, int start, int r, int c){
    queue<int> q;
    q.push(start);


    while (!q.empty()){
        
    }
    
}

int main(){
    int r, c;
    cin >> r >> c;

    vector<vector<int>> gird(r, vector<int> (c));
    vector<vector<bool>> visited(r, vector<bool> (c, false));

    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char temp;
            cin >> temp;
            if(temp == '.'){
                gird[i][j] = 0;
            }else{
                gird[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << gird[i][j] << " ";
        }
        cout << endl;
    }


}