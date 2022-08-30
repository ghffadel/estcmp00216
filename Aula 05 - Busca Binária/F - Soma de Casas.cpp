# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

typedef long long ll;

const int N = 1e5 + 10;

int n;
ll k, vet[N];

int binary_search (ll first_value, ll sum) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (first_value + vet[mid] == sum) {
            return mid;
        }
        
        else if (first_value + vet[mid] < sum) {
            left = mid + 1;
        }
        
        else {
            right = mid;
        }
    }
    
    return -1;
}

int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    
    cin >> k;
    
    for (int i = 0; i < n; i++) {
        int position = binary_search(vet[i], k);
        
        if (position != -1) {
            cout << vet[i] << " " << vet[position] << "\n";
            exit(0);
        }
    }
}