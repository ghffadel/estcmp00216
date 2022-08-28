# include <bits/stdc++.h>
 
using namespace std;
 
# define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int available, answer, n;
vector<pair<int, int>> schedules;
 
int main () {_
    cin >> n;
    
    schedules.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> schedules[i].second >> schedules[i].first;
    }
    
    sort(schedules.begin(), schedules.end());
    
    for (auto [end, start]: schedules) {
        if (start >= available) {
            answer++;
            available = end;
        }
    }
    
    cout << answer << "\n";
}