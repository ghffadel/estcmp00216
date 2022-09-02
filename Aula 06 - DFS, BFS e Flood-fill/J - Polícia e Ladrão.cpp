# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define WALL 1

enum is_visited { UNVISITED, VISITED };

const int N = 5;

int grid[N][N], t, visited[N][N];
vector<pair<int, int>> directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_valid (int row, int column) {
    return 0 <= row && row < N && 0 <= column && column < N;
}

void flood_fill (int row, int column) {
    if (!is_valid(row, column) || grid[row][column] == WALL || visited[row][column] == VISITED) {
        return;
    }
    
    visited[row][column] = VISITED;
    
    for (auto [new_row, new_column]: directions) {
        flood_fill(row + new_row, column + new_column);
    }
}

int main () {_
    cin >> t;
    
    while (t--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
                visited[i][j] = UNVISITED;
            }
        }
        
        flood_fill(0, 0);
        
        if (visited[N - 1][N - 1] == VISITED) {
            cout << "COPS\n";
        }
        
        else {
            cout << "ROBBERS\n";
        }
    }
}