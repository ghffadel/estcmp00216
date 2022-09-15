# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int INF = 1e9 + 10;
const int N = 1e5 + 10;

int dp[N], h[N], k, n;

int main () {_
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    for (int i = 1; i < n; i++) {
        dp[i] = INF;
        
        // Check the best value of k to perform the jump
        for (int j = i - 1; j >= 0 && j >= i - k; j--) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    
    cout << dp[n - 1] << "\n";
}