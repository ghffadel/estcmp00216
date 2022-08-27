# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

const ll MOD = 24 * 60 * 60;

ll exponent, hours, minutes, seconds;
string x;

ll binary_exponentiation (ll base, ll exponent, ll modulus) {
    ll result = 1;
    
    base %= modulus;
    
    while (exponent) {
        if (exponent & 1) {
            (result *= base) %= modulus;
        }
        
        (base *= base) %= modulus;
        exponent >>= 1;
    }
    
    return result;
}

int main () {_
    cin >> x;
    
    for (char digit: x) {
        exponent = (exponent * 10 + (digit - '0')) % MOD;
    }
    
    seconds = binary_exponentiation(2LL, exponent, MOD) - 1;
    hours = seconds / 3600, seconds %= 3600;
    minutes = seconds / 60, seconds %= 60;
    
    cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << "\n";
}