# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;

const int N = 1e2 + 10;

int n, t;
ll h[N];
 
int main () {_
    cin >> t;
    
    while (t--) {
        bool possible = true;
        ll sum = 0;
        
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            
            sum += h[i];
            
            // Sum of the values of all blocks up to i must be at least i * (i + 1) / 2, which is the sum of [0, 1, 2, ..., i]
            if (sum < i * (i + 1) / 2) {
                possible = false;
            }
        }
        
        if (possible) {
            cout << "YES\n";
        }
        
        else {
            cout << "NO\n";
        }
    }
}