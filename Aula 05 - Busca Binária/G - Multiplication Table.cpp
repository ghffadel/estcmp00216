# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

ll n;

// Function that represents how many numbers in the multiplication table are less than or equal to x
ll f (ll x) {
    ll result = 0;
    
    for (ll i = 1; i <= n; i++) {
        result += min(x / i, n);
    }
    
    return result;
}

int main () {_
    cin >> n;
    
    ll left = 1, right = n * n;
    
    // The median will have at least (n * n + 1) / 2 numbers less than or equal to it
    // Search for the smallest x such that f(x) >= (n * n + 1) / 2 
    while (left < right) {
        ll mid = left + (right - left) / 2;
        
        if (f(mid) >= (n * n + 1) / 2) {
            right = mid;
        }
        
        else {
            left = mid + 1;
        }
    }
    
    cout << right << "\n";
}