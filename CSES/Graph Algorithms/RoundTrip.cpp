#include <bits/stdc++.h>
using namespace std;
 
#define PB push_back
#define sz(x) ((int) x.size())
int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;
 
bool dfs(int v, int par) { 
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; 
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}
 
void find_cycle() {
    visited.assign(n+1, false);
    parent.assign(n+1, -1);
    cycle_start = -1;
 
    for (int v = 1; v < n+1; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }
 
    if (cycle_start == -1) {
        cout <<"IMPOSSIBLE";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
 
        cout << sz(cycle) << "\n";
        for (int v : cycle)
            cout << v << " ";
    }
}
 
int main(){
    int a, b; cin >> n >> m;
    adj.assign(n+1,vector<int>());
    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    find_cycle();
    return 0;
}
