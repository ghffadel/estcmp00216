# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;

const int N = 2e5 + 10;

int n;
ll x[N];
 
int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    ll current = x[0], maximum = x[0];
    
    for (int i = 1; i < n; i++) {
        current = max(current + x[i], x[i]);
        maximum = max(maximum, current);
    }
    
    cout << maximum << "\n";
}