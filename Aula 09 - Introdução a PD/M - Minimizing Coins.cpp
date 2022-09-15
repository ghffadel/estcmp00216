# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 1e9 + 10;
const int N = 1e6 + 10;

int c[N], dp[N], n, x;

int main () {_
    cin >> n >> x;
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    // Cannot use coins to produce sum 0
    dp[0] = 0;
    
    for (int i = 1; i <= x; i++) {
        // dp[i] = minimum number of coins with sum i.
        dp[i] = INF;
    }
    
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0) {
                // c[j] = last coin added to get sum i
                // dp[i - c[j]] coins are needed to get value i - c[j], and 1 coin for value c[j]
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}