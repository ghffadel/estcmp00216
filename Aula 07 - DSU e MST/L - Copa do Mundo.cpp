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

int cost, depth[N], f, n, parent[N], r;
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
    cin >> n >> f >> r;
    
    edges.resize(f + r);
    
    for (int i = 1; i <= n; i++) {
        depth[i] = 0;
        parent[i] = i;
    }
    
    for (int i = 0; i < f + r; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    sort(edges.begin(), edges.begin() + f);
    sort(edges.begin() + f, edges.end());
    
    for (auto [u, v, weight]: edges) {
        if (find_set(u) != find_set(v)) {
            cost += weight;
            union_sets(u, v);
        }
    }
        
    cout << cost << "\n";
}