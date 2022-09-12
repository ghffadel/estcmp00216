# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef pair<int, int> ii;

const int INF = INT_MAX;
const int N = 1e2 + 10;

int dist[N], m, n, u, v, w;
vector<ii> adj[N];

int dijkstra (int s, int t) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        
        pq.pop();
        
        if (d > dist[u]) {
            continue;
        }
        
        if (u == t) {
            return dist[u];
        }
        
        for (auto [v, w]: adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[t] == INF ? -1 : dist[t];
}

int main () {_
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    cout << dijkstra(1, n) << "\n";
}