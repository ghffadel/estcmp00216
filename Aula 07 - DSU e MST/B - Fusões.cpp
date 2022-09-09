# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 1e5 + 10;

char query;
int a, b, depth[N], k, n, parent[N];

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
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        depth[i] = 0;
        parent[i] = i;
    }
    
    while (k--) {
        cin >> query >> a >> b;
        
        if (query == 'C') {
            cout << "NS"[find_set(a) == find_set(b)] << "\n";
        }
        
        else {
            union_sets(a, b);
        }
    }
}