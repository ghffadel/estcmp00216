# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

const int BASE = 26;
const int MAX = 1e3 + 10;
const ll MOD = 1e9 + 7;

map<int, ll> powers;
string original;

ll convert () {
    int n = original.size() - 1;
    ll result = 0;
    
    for (char digit: original) {
        (result += ((digit - 'A') * powers[n]) % MOD) %= MOD;
        n--;
    }
    
    return result;
}

int main () {_
    powers[0] = 1;
    
    for (ll i = 1; i < MAX; i++) {
        powers[i] = (BASE * powers[i - 1]) % MOD;
    }
    
    while (cin >> original) {
        cout << convert() << "\n";
    }
}