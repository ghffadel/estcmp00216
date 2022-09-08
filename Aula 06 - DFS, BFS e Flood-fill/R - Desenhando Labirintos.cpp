# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

enum is_visited { UNVISITED, VISITED };

const int N = 5e1 + 10;

int a, moves, n, t, v, x, y;
vector<int> graph[N], visited(N);

void dfs (int node) {
    visited[node] = VISITED;
    
    for (int child: graph[node]) {
        if (!visited[child]) {
            dfs(child);
            moves += 2;
        }
    }
}

int main () {_
    cin >> t;
    
    while (t--) {
        cin >> n >> v >> a;
        
        moves = 0;
        
        for (int i = 0; i < v; i++) {
            graph[i].clear();
            visited[i] = UNVISITED;
        }
        
        while (a--) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        dfs(n);
        
        cout << moves << "\n";
    }
}