#include <bits/stdc++.h>
using namespace std;

#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"

vector<vector<int>> adj;
vector<int> visited;
vector<int> distancias;
vector<int> color;

void bfs(int x){
    queue<int> q;
    visited[x]=true;
    q.push(x);
    distancias[x]=0;
    while(!q.empty()){
        int s=q.front(); q.pop();
        for(auto &u: adj[s]){
            if(visited[u]) continue;
            visited[u]=true;
            distancias[u]=distancias[s]+1;
            q.push(u);
        }
    }
}

int main(){
    // freopen("planting.in", "r", stdin);
	// freopen(" planting.out", "w", stdout);
    int n, a, b; cin >> n;
    adj.assign(n+1, vector<int>());
    distancias.assign(n+1, -1);
    visited.assign(n+1, false);
    color.assign(n+1, -1);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    print(distancias);
    return 0;
}