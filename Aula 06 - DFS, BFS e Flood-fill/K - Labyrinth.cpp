# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define WALL '#'
# define START 'A'
# define END 'B'
 
const int N = 1e3 + 10;
 
enum is_possible { IMPOSSIBLE, POSSIBLE };
enum is_visited { UNVISITED, VISITED };

bool visited[N][N];
char grid[N][N];
int m, n, predecessor[N][N];
pair<int, int> finish, start;
string description = "URDL";
vector<pair<int, int>> directions {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
 
bool is_valid (int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] != WALL && visited[x][y] == UNVISITED;
}
 
bool bfs (pair<int, int> source, pair<int, int> destination) {
    queue<pair<int, int>> vertices_queue;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            predecessor[i][j] = -1;
        }
    }
    
    vertices_queue.push(source);
    visited[source.first][source.second] = VISITED;
    
    while (!vertices_queue.empty()) {
        pair<int, int> current = vertices_queue.front();
        
        if (current == destination) {
            return POSSIBLE;
        }
        
        vertices_queue.pop();
        
        for (int i = 0; i < 4; i++) {
            pair<int, int> next_position = {current.first + directions[i].first, current.second + directions[i].second};
            
            if (is_valid(next_position.first, next_position.second)) {
                predecessor[next_position.first][next_position.second] = i;
                visited[next_position.first][next_position.second] = VISITED;
                vertices_queue.push(next_position);
            }
        }
    }
    
    return IMPOSSIBLE;
}
 
void print_path (pair<int, int> source, pair<int, int> destination) {
    pair<int, int> current = destination;
    string path;
    
    while (current != source) {
        int previous_direction = predecessor[current.first][current.second];
        path += description[previous_direction];
        current = {current.first - directions[previous_direction].first, current.second - directions[previous_direction].second};
    }
    
    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n" << path << "\n";
}
 
int main () {_
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            
            if (grid[i][j] == START) {
                start = {i, j};
            }
            
            else if (grid[i][j] == END) {
                finish = {i, j};
            }
        }
    }
    
    if (bfs(start, finish) == POSSIBLE) {
        cout << "YES\n";
        print_path(start, finish);
    }
    
    else {
        cout << "NO\n";
    }
}