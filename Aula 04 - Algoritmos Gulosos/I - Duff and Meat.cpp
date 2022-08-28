# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e5 + 10;

int a[N], n, p[N], smallest = INT_MAX, total;
 
int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i];
        smallest = min(smallest, p[i]);
        total += smallest * a[i];
    }
    
    cout << total << "\n";
}