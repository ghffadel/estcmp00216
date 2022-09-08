# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define SHIP '#'
# define WATER '.'

enum is_visited { UNVISITED, VISITED };

const int N = 1e2 + 10;

int c, destroyed, k, l, m, n, ship_number, visited[N][N];
map<int, set<pair<int, int>>> positions;
string grid[N];
vector<pair<int, int>> directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_valid (int row, int column) {
    return 1 <= row && row <= n && 1 <= column && column <= m;
}

void flood_fill (int row, int column) {
    if (!is_valid(row, column) || grid[row][column] == WATER || visited[row][column] == VISITED) {
        return;
    }
    
    positions[ship_number].insert({row, column});
    grid[row][column] = WATER;
    visited[row][column] = VISITED;
    
    for (auto [new_row, new_column]: directions) {
        flood_fill(row + new_row, column + new_column);
    }
}

int main () {_
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i].insert(0, 1, WATER);
        
        for (int j = 1; j <= m; j++) {
            visited[i][j] = UNVISITED;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j] == UNVISITED && grid[i][j] == SHIP) {
                flood_fill(i, j);
                ship_number++;
            }
        }
    }
    
    cin >> k;
    
    while (k--) {
        cin >> l >> c;
        
        for (int i = 0; i < ship_number; i++) {
            auto it = positions[i].find({l, c});
            
            if (it != positions[i].end()) {
                positions[i].erase(it);
            }
        }
    }
    
    for (int i = 0; i < ship_number; i++) {
        if (positions[i].empty()) {
            destroyed++;
        }
    }
    
    cout << destroyed << "\n";
}