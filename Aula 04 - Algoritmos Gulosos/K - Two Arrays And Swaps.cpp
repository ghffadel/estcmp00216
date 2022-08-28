# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 3e1 + 10;

int a[N], b[N], k, n, t;
 
int main () {_
    cin >> t;
    
    while (t--) {
        int sum = 0;
        
        cin >> n >> k;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        
        for (int i = 0; i < k; i++) {
            if (b[i] > a[i]) {
                swap(a[i], b[i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        
        cout << sum << "\n";
    }
}