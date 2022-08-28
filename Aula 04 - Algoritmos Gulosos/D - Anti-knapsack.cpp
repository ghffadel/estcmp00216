# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int k, n, t;
 
int main () {_
    cin >> t;
    
    while (t--) {
        vector<int> answer;
        
        cin >> n >> k;
        
        for (int i = (k + 1) / 2; i <= n; i++) {
            if (i != k) {
                answer.push_back(i);
            }
        }
        
        cout << answer.size() << "\n";
        
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " \n"[i == answer.size() - 1];
        }
    }
}