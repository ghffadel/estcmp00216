# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define IMPOSSIBLE 0

enum is_visited { UNVISITED, VISITED };

const int N = 1e5 + 10;

bool visited[N];
int a, b, distances[N], m, n, predecessor[N];
vector<int> graph[N];

bool bfs (int source, int destination) {
    queue<int> vertices_queue;
    
    for (int i = 1; i <= n; i++) {
        distances[i] = INT_MAX;
        predecessor[i] = -1;
    }
    
    distances[source] = 0;
    visited[source] = VISITED;
    vertices_queue.push(source);
    
    while (!vertices_queue.empty()) {
        int node = vertices_queue.front();
        
        vertices_queue.pop();
        
        for (int child: graph[node]) {
            if (visited[child] == UNVISITED) {
                distances[child] = distances[node] + 1;
                predecessor[child] = node;
                visited[child] = VISITED;
                vertices_queue.push(child);
                
                if (child == destination) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

void print_path (int source, int destination) {
    if (bfs(source, destination) == IMPOSSIBLE) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    int current = destination;
    vector<int> path;
    
    while (current != -1) {
        path.insert(path.begin(), current);
        current = predecessor[current];
    }
    
    int path_size = path.size();
    
    cout << path_size << "\n";
    
    for (int i = 0; i < path_size; i++) {
        cout << path[i] << " \n"[i == path_size - 1];
    }
}

int main () {_
    cin >> n >> m;
    
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    print_path(1, n);
}