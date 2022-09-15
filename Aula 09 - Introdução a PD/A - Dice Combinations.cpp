# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int dp[N], n;

int main () {_
    cin >> n;
    
    // There is only one way to make sum 0
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, 6); j++) {
            // dp[i] = Number of ways to make sum i using numbers from 1 to 6.
            (dp[i] += dp[i - j]) %= MOD;
        }
    }
    
    cout << dp[n] << "\n";
}