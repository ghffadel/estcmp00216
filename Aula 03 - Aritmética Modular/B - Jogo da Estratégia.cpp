# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int j, r, turn;
map<int, int> points;
pair<int, int> winner = {0, 0};

int main () {_
    cin >> j >> r;
    
    for (int i = 0, x; i < j * r; i++) {
        cin >> x;
        points[turn + 1] += x;
        turn = (turn + 1) % j;
    }
    
    for (int i = 1; i <= j; i++) {
        if (points[i] >= winner.second) {
            winner = {i, points[i]};
        }
    }
    
    cout << winner.first << "\n";
}