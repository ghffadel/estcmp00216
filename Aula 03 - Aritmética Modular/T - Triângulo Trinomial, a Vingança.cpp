# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

const ll MOD = (1LL << 31) - 1;

ll row;

ll binary_exponentiation (ll base, ll exponent) {
    ll result = 1;
    
    while (exponent) {
        if (exponent & 1) {
            (result *= base) %= MOD;
        }
        
        (base *= base) %= MOD;
        exponent >>= 1;
    }
    
    return result;
}

int main () {_
    cin >> row;
    cout << binary_exponentiation(3, row) << "\n";
}