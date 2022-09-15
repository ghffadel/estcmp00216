# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 1e5 + 10;

int best, dp[N][3], mat[N][3], n;

int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat[i][j];
        }
    }
    
    // 0-column: Swim in the sea
    // 1-column: Catch bugs in the mountains
    // 2-column: Do homework at home
    for (int j = 0; j < 3; j++) {
        dp[0][j] = mat[0][j]; 
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            // For each activity j, check which is the best result coming from an activity different than j
            dp[i][j] = mat[i][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
        }
    }
    
    // Check the path that had the best result
    for (int j = 0; j < 3; j++) {
        best = max(best, dp[n - 1][j]);
    }
    
    cout << best << "\n";
}