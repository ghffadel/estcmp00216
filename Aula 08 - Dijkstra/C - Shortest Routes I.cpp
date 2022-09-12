# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 10;

int m, n, u, v, w;
ll dist[N];
vector<ii> adj[N];

void dijkstra (int s) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
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
        dist[i] = LLONG_MAX;
    }
    
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    dijkstra(1);
    
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " \n"[i == n];
    }
}