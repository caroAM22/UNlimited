#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> parent;
vector<int> dist;
 
void bfs(int x){
    queue<int> q;
    q.push(x); 
    dist[x]=1;
    while(!q.empty()){
        int u=q.front(); q.pop(); 
        for(int& v: adj[u]){
            if(dist[u]+1<dist[v]){
                parent[v]=u;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}
 
 
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int n, m, a,b; cin >> n >> m;
    adj.assign(n,vector<int>());
    parent.assign(n,-1);
    dist.assign(n,1e9+7);
    for(int i=0; i<m; i++){
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    if(dist[n-1]!=1e9+7){
        int u=n-1;
        vector<int> p;
        while(parent[u]!=-1){
            p.push_back(u);
            u=parent[u];
        }
        reverse(p.begin(),p.end());
        cout << dist[n-1] << "\n";
        cout << 1 << " ";
        for(int& x: p){
            cout << x+1 << " ";
        }
    }
    else cout << "IMPOSSIBLE";
    return 0;
}
