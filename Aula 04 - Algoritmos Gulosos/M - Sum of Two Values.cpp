# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 2e5 + 10;

int a[N], n, x;
map<int, int> position;
 
int main () {_
    cin >> n >> x;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        position[a[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        if (position[x - a[i]] > 0 && position[x - a[i]] != i) {
            cout << i << " " << position[x - a[i]] << "\n";
            exit(0);
        }
    }
    
    cout << "IMPOSSIBLE\n";
}