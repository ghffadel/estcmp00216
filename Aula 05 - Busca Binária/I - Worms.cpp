# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int N = 1e6 + 10;

int a[N], m, n, q;
vector<int> piles;

int lower_bound (int value) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (piles[mid] < value) {
            left = mid + 1;
        }
        
        else {
            right = mid;
        }
    }
    
    return left;
}

int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        if (i == 0) {
            piles.push_back(1);
        }
        
        else {
            piles.push_back(piles.back() + a[i - 1]);
        }
    }
    
    cin >> m;
    
    while (m--) {
        cin >> q;
        
        int position = lower_bound(q);
        
        if (piles[position] == q) {
            position++;
        }
        
        cout << position << "\n";
    }
}