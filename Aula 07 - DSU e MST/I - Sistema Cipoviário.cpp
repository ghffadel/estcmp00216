# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

const int N = 1e3 + 10;

struct Edge {
    int u, v, weight;
    
    bool operator < (Edge const& other) {
        return weight < other.weight;
    }
};

int depth[N], instance, m, n, parent[N];
vector<Edge> edges;

int find_set (int x) {
    if (x == parent[x]) {
        return x;
    }
    
    return parent[x] = find_set(parent[x]);
}

void union_sets (int x, int y) {
    x = find_set(x);
    y = find_set(y);
    
    if (x != y) {
        if (depth[x] < depth[y]) {
            swap(x, y);
        }
        
        parent[y] = x;
        
        if (depth[x] == depth[y]) {
            depth[x]++;
        }
    }
}

int main () {_
    while (cin >> n >> m) {
        ll cost = 0;
        
        edges.resize(m);
        
        for (int i = 1; i <= n; i++) {
            depth[i] = 0;
            parent[i] = i;
        }
        
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        }
        
        sort(edges.begin(), edges.end());
        
        for (auto [u, v, weight]: edges) {
            if (find_set(u) != find_set(v)) {
                cost += weight;
                union_sets(u, v);
            }
        }
        
        cout << "Instancia " << ++instance << "\n" << cost << "\n\n";
    }
}