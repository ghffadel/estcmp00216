# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define WALL 'X'

enum is_visited { UNVISITED, VISITED };

const int N = 5e1 + 10;

int m, n, visited[N][N];
string grid[N];
vector<pair<int, int>> directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_valid (int row, int column) {
    return 0 <= row && row < n && 0 <= column && column < m;
}

void flood_fill (int row, int column) {
    if (!is_valid(row, column) || grid[row][column] == WALL || visited[row][column] == VISITED) {
        return;
    }
    
    grid[row][column] = 'T';
    visited[row][column] = VISITED;
    
    for (auto [new_row, new_column]: directions) {
        flood_fill(row + new_row, column + new_column);
    }
}

int main () {_
    while (cin >> n >> m && (n || m)) {
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            
            for (int j = 0; j < m; j++) {
                visited[i][j] = UNVISITED;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == UNVISITED && grid[i][j] == 'T') {
                    flood_fill(i, j);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << grid[i] << "\n";
        }
        
        cout << "\n";
    }
}