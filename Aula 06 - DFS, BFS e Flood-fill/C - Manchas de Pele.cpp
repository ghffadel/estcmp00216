# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

enum color_names { WHITE, BLACK };
enum is_visited { UNVISITED, VISITED };

const int N = 1e3 + 10;

int colors[N][N], current_color, grid[N][N], m, n, visited[N][N];
vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_valid (int row, int column) {
    return 0 <= row && row < n && 0 <= column && column < m;
}

void flood_fill (int row, int column) {
    if (!is_valid(row, column) || visited[row][column] == VISITED || grid[row][column] == WHITE) {
        return;
    }
    
    visited[row][column] = VISITED;
    colors[row][column] = current_color;
    
    for (auto [next_row, next_column]: directions) {
        flood_fill(row + next_row, column + next_column);
    }
}

int main () {_
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j] = UNVISITED;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == UNVISITED && grid[i][j] == BLACK) {
                flood_fill(i, j);
                current_color++;
            }
        }
    }
    
    cout << current_color << "\n";
}