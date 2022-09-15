# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 1e5 + 10;

int dp[N], h[N], n;

int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    // For i = 1, the cost is the jump itself
    dp[1] = abs(h[1] - h[0]);
    
    for (int i = 2; i < n; i++) {
        // Check if it's better to come from i - 1 or i - 2
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    
    cout << dp[n - 1] << "\n";
}