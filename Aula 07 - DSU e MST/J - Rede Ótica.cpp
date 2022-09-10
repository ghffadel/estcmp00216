# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 1e2 + 10;

struct Edge {
    int u, v, weight;
    
    bool operator < (Edge const& other) {
        return weight < other.weight;
    }
};

int depth[N], m, n, parent[N], test_case;
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
    while (cin >> n >> m && n) {
        vector<pair<int, int>> result;
        
        edges.resize(m);
        
        for (int i = 1; i <= n; i++) {
            depth[i] = 0;
            parent[i] = i;
        }
        
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        }
        
        sort(edges.begin(), edges.end());
        
        for (Edge edge: edges) {
            if (find_set(edge.u) != find_set(edge.v)) {
                result.push_back({min(edge.u, edge.v), max(edge.u, edge.v)});
                union_sets(edge.u, edge.v);
            }
        }
        
        cout << "Teste " << ++test_case << "\n";
        
        for (auto [f, s]: result) {
            cout << f << " " << s << "\n";
        }
        
        cout << "\n";
    }
}