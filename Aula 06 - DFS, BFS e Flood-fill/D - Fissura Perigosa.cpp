# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define LAVA -1

enum is_visited { UNVISITED, VISITED };

const int N = 5e2 + 10;

char height;
int f, grid[N][N], n, visited[N][N];
vector<pair<int, int>> directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_valid (int row, int column) {
    return 0 <= row && row < n && 0 <= column && column < n;
}

void flood_fill (int row, int column) {
    if (!is_valid(row, column) || grid[row][column] > f || visited[row][column] == VISITED) {
        return;
    }
    
    grid[row][column] = LAVA;
    visited[row][column] = VISITED;
    
    for (auto [new_row, new_column]: directions) {
        flood_fill(row + new_row, column + new_column);
    }
}

int main () {_
    cin >> n >> f;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> height;
            grid[i][j] = height - '0';
            visited[i][j] = UNVISITED;
        }
    }
    
    flood_fill(0, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == LAVA) {
                cout << "*";
            }
            
            else {
                cout << grid[i][j];
            }
        }
        
        cout << "\n";
    }
}