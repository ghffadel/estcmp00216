# include <bits/stdc++.h>

using namespace std;

# define _ ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

enum is_visited { UNVISITED, VISITED };

const int N = 1e3 + 10;

int house_number, n, people_count, visited[N];
map<int, int> houses_map;
string grid[N];
vector<int> graph[N], people_in_house;

void dfs (int node) {
    houses_map[node] = house_number;
    people_count++;
    visited[node] = VISITED;
    
    for (auto child: graph[node]) {
        if (visited[child] == UNVISITED) {
            dfs(child);
        }
    }
}

int main () {_
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        visited[i] = UNVISITED;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'S') {
                graph[i].push_back(j);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == UNVISITED) {
            house_number++;
            people_count = 0;
            dfs(i);
            people_in_house.push_back(people_count);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (houses_map[i] == houses_map[j] && grid[i][j] == 'D') {
                cout << "-1\n";
                exit(0);
            }
        }
    }
    
    int number_of_houses = people_in_house.size();
    
    sort(people_in_house.rbegin(), people_in_house.rend());
    
    cout << number_of_houses << "\n";
    
    for (int i = 0; i < number_of_houses; i++) {
        cout << people_in_house[i] << " \n"[i == number_of_houses - 1];
    }
}