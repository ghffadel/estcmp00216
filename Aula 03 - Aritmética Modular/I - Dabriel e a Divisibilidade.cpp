# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int m, x;
string number;
vector<int> divisors;

bool check_divisibility (int divisor) {
    int remainder = 0;
    
    for (char digit: number) {
        remainder = (2 * remainder + (digit - '0')) % divisor;
    }
    
    return remainder == 0;
}

int main () {_
    cin >> number >> m;
    
    while (m--) {
       cin >> x;
       
       if (check_divisibility(x)) {
            divisors.push_back(x);
       }
    }
    
    if (divisors.empty()) {
        cout << "Nenhum\n";
    }
    
    else {
        sort(divisors.begin(), divisors.end());
        
        for (int i = 0; i < divisors.size(); i++) {
            cout << divisors[i] << " \n"[i == divisors.size() - 1];
        }
    }
}