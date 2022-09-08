# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

enum is_visited { UNVISITED, VISITED };

const int N = 1e5 + 10;

int a, b, m, n, visited[N];
vector<int> bridges, graph[N];

void dfs (int node) {
    visited[node] = VISITED;
    
    for (auto child: graph[node]) {
        if (visited[child] == UNVISITED) {
            dfs(child);
        }
    }
}

int main () {_
    cin >> n >> m;
    
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == UNVISITED) {
            bridges.push_back(i);
            dfs(i);
        }   
    }
    
    cout << bridges.size() - 1 << "\n";
    
    for (int i = 0; i < bridges.size() - 1; i++) {
        cout << bridges[i] << " " << bridges[i + 1] << "\n";
    }
}