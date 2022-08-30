# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int n, num, x, y;
vector<int> vet;

int lower_bound (int value) {
    int left = 0, right = vet.size();
    
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
    int left = 0, right = vet.size();
    
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
    while (cin >> n) {
        vet.clear();
        
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            
            for (int j = x; j <= y; j++) {
                vet.push_back(j);
            }
        }
        
        sort(vet.begin(), vet.end());
        
        cin >> num;
        
        int first = lower_bound(num);
        int last = upper_bound(num) - 1;
        
        if (vet[first] == num && vet[last] == num) {
            cout << num << " found from " << first << " to " << last << "\n";
        }
        
        else {
            cout << num << " not found\n";
        }
    }
}