# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, k;
// This multiset stores the values of the cubes that on the top of the towers
multiset<int> towers;
 
int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> k;
        
        // Check if there's a cube which is at the top of a tower and is greater than k
        auto greater_position = towers.upper_bound(k);
        
        // If it exists, k will go to the top of this tower and the previous value will be erased
        if (greater_position != towers.end()) {
            towers.erase(greater_position);
        }
        
        towers.insert(k);
    }
    
    cout << towers.size() << "\n";
}