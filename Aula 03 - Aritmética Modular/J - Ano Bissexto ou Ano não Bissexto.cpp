# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

bool bulukulu, first = true, huluculu, leap;
string year;

bool check_divisibility (int divisor) {
    int remainder = 0;
    
    for (char digit: year) {
        remainder = (10 * remainder + (digit - '0')) % divisor;
    }
    
    return remainder == 0;
}

int main () {_
    while (cin >> year) {
        if (!first) {
            cout << "\n";
        }
        
        else {
            first = false;
        }
        
        leap = ((check_divisibility(4) && !check_divisibility(100)) || check_divisibility(400));
        bulukulu = (check_divisibility(55) && leap);
        huluculu = check_divisibility(15);
        
        if (!leap && !huluculu) {
          cout << "This is an ordinary year.\n";
          continue;
        }
        
        if (leap) {
          cout << "This is leap year.\n";
        }
        
        if (huluculu) {
          cout << "This is huluculu festival year.\n";
        }
        
        if (bulukulu) {
          cout << "This is bulukulu festival year.\n";
        }
    }
}