# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int answer, t;
vector<int> available;
 
int main () {_
    for (int i = 13; i >= 0; i--) {
        available.push_back(1 << i);
    }
    
    cin >> t;
    
    for (int capacity: available) {
        if (!t) {
            break;
        }
        
        answer += t / capacity;
        t %= capacity;
    }
    
    cout << answer << "\n";
}