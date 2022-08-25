# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int n;

int main () {_
    while (cin >> n) {
        int digits = 0, remainder = n;
        
        while (remainder) {
            remainder = (10 * remainder + 1) % n;
            digits++;
        }
        
        cout << digits << "\n";
    }
}