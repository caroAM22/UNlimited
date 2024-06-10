#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define S second
#define F first
#define sz(x) ((int) x.size())
vector<bool> visited;
vector<vector<int>> adj;

int n, m; 

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty()){
        int s=q.front(); q.pop();
        for(int u: adj[s]){
            if(visited[u]) continue;
            visited[u]=true;
            q.push(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int a, b;
    cin >> n >> m;
    visited.assign(n+1,false);
    adj.assign(n+1,vector<int>());
    vector<int> res;

    for(int i=0; i<m; ++i){
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    int roads=-1;
    for(int i=1; i<n+1; ++i){
        if(!visited[i]){
            bfs(i);
            roads++;
            res.PB(i);
        }
    }
    cout << roads << "\n";
    for(int i=0; i<sz(res)-1; ++i){
        cout << res[i] << " " << res[i+1] << "\n";
    }
    return 0;
}