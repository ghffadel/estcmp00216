# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
# define EMPTY '.'

const int MOD = 1e9 + 7;
const int N = 1e3 + 10;

char grid[N][N];
int dp[N][N], n;

int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // There is only one way to reach the first position
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if it's possible to walk through this postion
            if (grid[i][j] == EMPTY) {
                // Check the possibilities coming from the top
                if (i > 0) {
                    (dp[i][j] += dp[i - 1][j]) %= MOD;
                }
                
                // Check the possibilities coming from the left
                if (j > 0) {
                    (dp[i][j] += dp[i][j - 1]) %= MOD;
                }
            }
            
            else {
                dp[i][j] = 0;
            }
        }
    }
    
    cout << dp[n - 1][n - 1] << "\n";
}