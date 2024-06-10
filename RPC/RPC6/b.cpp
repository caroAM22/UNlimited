#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
vector<int> tree[MAXN];
int subtree_size[MAXN];
int max_visit = 0;
int count_max_visit = 0;

// Perform DFS to calculate subtree sizes
void dfs(int u, int parent) {
    subtree_size[u] = 1;
    for (int v : tree[u]) {
        if (v != parent) {
            dfs(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

// Calculate maximum visit count and count edges with that visit count
void calculate_visits(int u, int parent, vector<int>& edge_visits) {
    for (int v : tree[u]) {
        if (v != parent) {
            calculate_visits(v, u, edge_visits);
            int visits = subtree_size[v] * (subtree_size[1] - subtree_size[v]);
            edge_visits.push_back(visits);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1);

    vector<int> edge_visits;
    calculate_visits(1, -1, edge_visits);

    for (int visits : edge_visits) {
        if (visits > max_visit) {
            max_visit = visits;
            count_max_visit = 1;
        } else if (visits == max_visit) {
            count_max_visit++;
        }
    }
  
    cout << max_visit << " " << count_max_visit << "\n";
    
    return 0;
}
