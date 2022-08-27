# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

ll n;

ll binary_exponentiation (ll base, ll exponent, ll modulus) {
    ll result = 1;
    
    base %= modulus;
    
    while (exponent) {
        if (exponent & 1) {
            (result *= base) %= modulus;
        }
        
        (base *= base) %= modulus;
        exponent >>= 1;
    }
    
    return result;
}

int main () {_
    while (cin >> n) {
        ll m = 1;
        
        for (ll i = n; i > 0; i /= 10) {
            m *= 10;
        }
        
        if (binary_exponentiation(n, n, m) == n) {
            cout << "SIM\n";
        }
        
        else {
            cout << "NAO\n";
        }
    }
}