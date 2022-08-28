# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 2e5 + 10;

int n, rounds = 1, x[N];
map<int, int> positions;
 
int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        positions[x[i]] = i;
    }
    
    for (int i = 1; i < n; i++) {
        // The number of rounds will only increase if the position of x is after the position of x + 1
        if (positions[i] > positions[i + 1]) {
            rounds++;
        }
    }
    
    cout << rounds << "\n";
}