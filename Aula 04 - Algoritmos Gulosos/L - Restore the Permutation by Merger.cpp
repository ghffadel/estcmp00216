# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e2 + 10;

int a[N], n, t;
 
int main () {_
    cin >> t;
    
    while (t--) {
        map<int, int> appeared;
        vector<int> p;
        
        cin >> n;
        
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            
            if (!appeared[a[i]]) {
                p.push_back(a[i]);
                appeared[a[i]] = i + 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i == n - 1];
        }
    }
}