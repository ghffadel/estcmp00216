# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e4 + 10;

int a[N], n, q, test_case, x;

int binary_search (int value) {
    int left = 1, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (a[mid] < value) {
            left = mid + 1;
        }
        
        else {
            right = mid;
        }
    }
    
    if (a[left] == value) {
        return left;
    }
    
    else {
        return -1;
    }
}
 
int main () {_
    while (cin >> n >> q && (n || q)) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        sort(a + 1, a + n + 1);
        
        cout << "CASE# " << ++test_case << ":\n";
        
        while (q--) {
            cin >> x;
            
            int position = binary_search(x);
            
            if (position != -1) {
                cout << x << " found at " << position << "\n";
            }
            
            else {
                cout << x << " not found\n";
            }
        }
    }
}