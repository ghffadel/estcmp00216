# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 10;
const ll INF = 1e18 + 10;

int m, n, u, v, w;
ll ans = INF;
vector<ii> adj[N], rev_adj[N];

vector<ll> dijkstra (int s) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist (n + 1, INF);
    
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        
        pq.pop();
        
        if (d > dist[u]) {
            continue;
        }
        
        for (auto [v, w]: (s == 1 ? adj[u] : rev_adj[u])) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main () {_
    cin >> n >> m;
    
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // Adjacency list from the destination vertex to the origin vertex
        rev_adj[v].push_back({u, w});
    }
    
    // Distances from vertex 1 to the others
    vector<ll> dist_from_1 = dijkstra(1);
    // Distances from all vertices to vertex N
    vector<ll> dist_to_N = dijkstra(n);
    
    for (int u = 1; u <= n; u++) {
        for (auto [v, w]: adj[u]) {
            // Calculates the minimum distance of the following path: 1 -> U -> V -> N
            // The discount is used in the U -> V path, which has a weight W
            ans = min(ans, dist_from_1[u] + (w / 2) + dist_to_N[v]);
        }
    }
    
    cout << ans << "\n";
}