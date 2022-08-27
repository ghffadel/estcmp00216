# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

const int MAX = 2e6 + 10;
const ll MOD = 1300031;

int c, n, t;
ll factorial[MAX];

ll modular_inverse (ll a, ll b) {
    return a > 1 ? b - modular_inverse(b % a, a) * b / a : 1;
}

int main () {_
    factorial[0] = 1;
    
    for (ll i = 1; i < MAX; i++) {
        factorial[i] = (i * factorial[i - 1]) % MOD;
    }
    
    cin >> t;
        
    while (t--) {
        cin >> n >> c;
        
        // Number of non-negative integral solutions of equation x1 + x2 + …… + xn = c is given by (n + c - 1)! / (n - 1)! * c!
        ll answer = factorial[n + c - 1];
        (answer *= modular_inverse(factorial[n - 1], MOD)) %= MOD;
        (answer *= modular_inverse(factorial[c], MOD)) %= MOD;
        
        cout << answer << "\n";
    }
    
}