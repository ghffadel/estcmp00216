# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 1e5 + 10;

int a[N], k, n, x;

int upper_bound (int value) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (a[mid] <= value) {
            left = mid + 1;
        }
        
        else {
            right = mid;
        }
    }
    
    return left;
}

int main () {_
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    while (k--) {
        cin >> x;
        
        int position = upper_bound(x) - 1;
        
        if (a[position] <= x) {
            cout << position + 1 << "\n";
        }
        
        else {
            cout << 0 << "\n";
        }
    }
}