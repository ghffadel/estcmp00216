# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 2e5 + 10;

int a[N], answer, b[N], i, j, k, m, n;
 
int main () {_
    cin >> n >> m >> k;
    
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (j = 0; j < m; j++) {
        cin >> b[j];
    }
    
    sort(a, a + n);
    sort(b, b + m);
    
    i = j = 0;
    
    while (i < n && j < m) {
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
            answer++;
            i++;
            j++;
        }
        
        else if (b[j] > a[i] + k) {
            i++;
        }
        
        else {
            j++;
        }
    }
    
    cout << answer << "\n";
}