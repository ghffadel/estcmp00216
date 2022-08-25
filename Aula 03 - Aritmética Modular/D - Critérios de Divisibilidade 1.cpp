# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

string number;

bool check_divisibility (int divisor) {
    int remainder = 0;
    
    for (char digit: number) {
        remainder = (10 * remainder + (digit - '0')) % divisor;
    }
    
    return remainder == 0;
}

int main () {_
    cin >> number;
    
    for (int x: {2, 3, 5}) {
        cout << "NS"[check_divisibility(x)] << "\n";
    }
}