# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

int n;
ll fat = 1, fib[N], pow2 = 2;

int main () {_
    cin >> n;
    
    fib[0] = fib[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        (fat *= i) %= MOD;
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
        (pow2 *= 2) %= MOD;
    }
    
    // Answer = fibonacci(n) * factorial(n) * (2 ^ n)
    // fibonacci(n) = Number of ways to tile an 2 x n rectangular board using 2 x 1 tiles
    // factorial(n) = Number of ways to rearrange tiles => [A1, A2], [B1, B2] != [B1, B2], [A1, A2]
    // 2 ^ n = Number of ways to rearrange couples within tiles => [A1, A2] != [A2, A1]
    cout << (((fib[n] * fat) % MOD) * pow2) % MOD << "\n";
}