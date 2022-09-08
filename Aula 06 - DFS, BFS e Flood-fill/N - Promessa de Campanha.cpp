# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

enum is_visited { UNVISITED, VISITED };

const int N = 1e2 + 10;

int m, n, t, visited[N], x, y;
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
    cin >> t;
    
    for (int test_case = 1; test_case <= t; test_case++) {
        int remaining = 0;
        
        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            visited[i] = UNVISITED;
        }
        
        while (m--) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        dfs(1);
        
        for (int i = 1; i <= n; i++) {
            if (visited[i] == UNVISITED) {
                dfs(i);
                remaining++;
            }
        }
        
        cout << "Caso #" << test_case << ": ";
        
        if (remaining == 0) {
            cout << "a promessa foi cumprida\n";
        }
        
        else {
            cout << "ainda falta(m) " << remaining << " estrada(s)\n";
        }
    }
}