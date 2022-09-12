# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define even first
# define odd second

typedef pair<int, int> ii;

const int INF = 1e9 + 10;
const int N = 1e4 + 10;

int m, n, u, v, w;
ii dist[N];
vector<ii> adj[N];

int dijkstra (int s, int t) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    dist[s].even = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        
        pq.pop();
        
        if (d > dist[u].even && d > dist[u].odd) {
            continue;
        }
        
        for (auto [v, w]: adj[u]) {
            // Check if it's possible to improve the odd distance to v
            if (dist[u].even + w < dist[v].odd) {
                dist[v].odd = dist[u].even + w;
                pq.push({dist[v].odd, v});
            }
            
            // Check if it's possible to improve the even distance to v
            if (dist[u].odd + w < dist[v].even) {
                dist[v].even = dist[u].odd + w;
                pq.push({dist[v].even, v});
            }
        }
    }
    
    // Return the even distance to destination if it's possible
    return dist[t].even == INF ? -1 : dist[t].even;
}

int main () {_
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        dist[i] = {INF, INF};
    }
    
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    cout << dijkstra(1, n) << "\n";
}