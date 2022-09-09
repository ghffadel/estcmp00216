# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 5e2 + 10;

struct Edge {
    int u, v, weight;
    
    bool operator < (Edge const& other) {
        return weight < other.weight;
    }
};

int c, cost, depth[N], m, n, parent[N], u, v;
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
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        depth[i] = 0;
        parent[i] = i;
    }
    
    while (m--) {
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
    
    sort(edges.begin(), edges.end());
    
    for (Edge edge: edges) {
        if (find_set(edge.u) != find_set(edge.v)) {
            cost += edge.weight;
            union_sets(edge.u, edge.v);
        }
    }
    
    cout << cost << "\n";
}