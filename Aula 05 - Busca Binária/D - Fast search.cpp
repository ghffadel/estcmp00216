# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

bool print_space;
int k, l, n, r;
vector<int> vet;

int lower_bound (int value) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (vet[mid] < value) {
            left = mid + 1;
        }
        
        else {
            right = mid;
        }
    }
    
    return left;
}

int upper_bound (int value) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (vet[mid] <= value) {
            left = mid + 1;
        }
        
        else {
            right = mid;
        }
    }
    
    return left;
}

int main () {_
    cin >> n;
    
    vet.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    
    sort(vet.begin(), vet.end());
    
    cin >> k;
    
    while (k--) {
        cin >> l >> r;
        
        int first = lower_bound(l);
        int last = upper_bound(r);
        
        if (print_space) {
            cout << " ";
        }
        
        else {
            print_space = true;
        }
        
        cout << last - first;
    }
    
    cout << "\n";
}