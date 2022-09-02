# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define BLACK 'o'
# define WHITE '.'

const int N = (1 << 10) + 10;

int clicks, m, n;
string grid[N];
vector<pair<int, int>> directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_valid (int row, int column) {
    return 0 <= row && row < n && 0 <= column && column < m;
}

void bfs (int row, int column) {
    queue<pair<int, int>> positions_queue;
    
    positions_queue.push({row, column});
    
    while (!positions_queue.empty()) {
        auto [row, column] = positions_queue.front();
        
        positions_queue.pop();
        
        if (grid[row][column] == WHITE) {
            grid[row][column] = BLACK;
            
            for (auto [new_row, new_column]: directions) {
                if (is_valid(row + new_row, column + new_column)) {
                    positions_queue.push({row + new_row, column + new_column});
                }
            }
        }
    }
}

int main () {_
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == WHITE) {
                bfs(i, j);
                clicks++;
            }
        }
    }
    
    cout << clicks << "\n";
}