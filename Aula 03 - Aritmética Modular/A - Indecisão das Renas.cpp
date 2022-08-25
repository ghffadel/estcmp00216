# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const int MAX = 9;

int a[MAX], sum;
string answer[] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};

int main () {_
    for (int i = 0; i < MAX; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    cout << answer[(sum - 1) % MAX] << "\n";
}