# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef pair<int, int> ii;

const int N = 1e3 + 10;

int dist[N], m, max_dist = INT_MIN, min_dist = INT_MAX, n, s, u, v, w;
vector<ii> adj[N];

void dijkstra (int s) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        
        pq.pop();
        
        if (d > dist[u]) {
            continue;
        }
        
        for (auto [v, w]: adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main () {_
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    cin >> s;
    
    dijkstra(s);
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] != INT_MAX && i != s) {
            max_dist = max(max_dist, dist[i]);
            min_dist = min(min_dist, dist[i]);
        }
    }
    
    cout << max_dist - min_dist << "\n";
}