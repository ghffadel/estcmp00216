# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int INF = 1e9 + 10;
const int N = 1e6 + 10;

int dp[N], n;

int main () {_
    cin >> n;
    
    dp[0] = 0;
    
    // dp[i] = minimum number of operations to go from i to zero.
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    
    for (int i = 1; i <= n; i++) {
        // dp[i] can be defined as the minimum value of dp[x - digit] + 1, for all digits of i
        for (char c: to_string(i)) {
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
    
    cout << dp[n] << "\n";
}