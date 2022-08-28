# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 2e5 + 10;

int answer, i, j, n, p[N], x;
 
int main () {_
    cin >> n >> x;
    
    for (i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    sort(p, p + n);
    
    answer = n, i = 0, j = n - 1;
    
    while (i < j) {
        if (p[i] + p[j] <= x) {
            answer--;
            i++;
        }
        
        j--;
    }
    
    cout << answer << "\n";
}