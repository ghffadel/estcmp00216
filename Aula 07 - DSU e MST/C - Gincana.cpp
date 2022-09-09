# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

enum is_visited { UNVISITED, VISITED };

const int N = 1e3 + 10;

int groups, m, n, u, v, visited[N];
vector<int> graph[N];

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
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == UNVISITED) {
            groups++;
            dfs(i);
        }   
    }
    
    cout << groups << "\n";
}