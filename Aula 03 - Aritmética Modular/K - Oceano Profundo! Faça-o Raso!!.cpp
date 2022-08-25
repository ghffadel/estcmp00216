# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int MOD = 131071;

string line, number;

bool check_divisibility (string number) {
    int remainder = 0;
    
    for (char digit: number) {
        if (digit == '#') {
            break;
        }
        
        remainder = (2 * remainder + (digit - '0')) % MOD;
    }
    
    return remainder == 0;
}

int main () {_
    while (cin >> line) {
        number += line;
        
        if (line[line.size() - 1] == '#') {
            if (check_divisibility(number)) {
                cout << "YES\n";
            }
            
            else {
                cout << "NO\n";
            }
            
            number = "";
        }
    }
}