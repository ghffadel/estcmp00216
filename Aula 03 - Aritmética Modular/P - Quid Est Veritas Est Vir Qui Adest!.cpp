# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

const int MAX = 1e3 + 10;
const ll MOD = 1e9 + 7;

ll factorial[MAX];
string word;

ll modular_inverse (ll a, ll b) {
    return a > 1 ? b - modular_inverse(b % a, a) * b / a : 1;
}

int main () {_
    factorial[0] = 1;
    
    for (ll i = 1; i < MAX; i++) {
        factorial[i] = (i * factorial[i - 1]) % MOD;
    }
    
    while (cin >> word) {
        map<char, int> letter_count;
        
        for (char letter: word) {
            letter_count[letter]++;
        }
        
        ll answer = factorial[word.size()];
        
        for (auto [key, value]: letter_count) {
            (answer *= modular_inverse(factorial[value], MOD)) %= MOD;
        }
        
        cout << answer % MOD << "\n";
    }
}