# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 2e5 + 10;

int c, dp[N][2], n, p[N];

int main () {_
    cin >> n >> c;
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    // 0-column: Not in an investment during the day i
    // 1-column: Is in an investment during the day i
    
    // dp[1][1] = Buy a stock on the first day
    dp[1][1] -= p[1] + c;
    
    for (int i = 2; i <= n; i++) {
        // Check if it's better not to invest now or sell the stock on day i
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + p[i]);
        // Check if it's better to wait to sell the stock on another day or if it is better to buy the stock on day i
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - p[i] - c);
    }
    
    // Print the result of the best path (or 0 if it goes bad anyway)
    cout << max({0, dp[n][0], dp[n][1]}) << "\n";
}