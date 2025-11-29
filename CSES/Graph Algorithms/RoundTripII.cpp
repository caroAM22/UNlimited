#include <bits/stdc++.h>
using namespace std;
 
#define PB push_back
#define sz(x) ((int) x.size())
int n, m;
vector<vector<int>> adj;
vector<int> visited;
vector<int> parent;
int cycle_start, cycle_end;
 
bool dfs(int v) { 
    visited[v] = 1;
    for (int u : adj[v]) {
       if(visited[u]==0){
          parent[u]=v;
          if(dfs(u)) return true;
       }else if(visited[u]==1){
        cycle_start=u;
        cycle_end=v;
        return true;
       }
    }
    visited[v] = 2;
    return false;
}
 
void find_cycle() {
    visited.assign(n+1, 0);
    parent.assign(n+1, -1);
    cycle_start = -1;
 
    for (int v = 1; v < n+1; v++) {
        if (visited[v]==0 && dfs(v))
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
        reverse(cycle.begin(), cycle.end());
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
    }
    find_cycle();
    return 0;
}