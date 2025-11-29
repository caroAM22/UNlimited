#include <bits/stdc++.h>
using namespace std;
 
#define sz(x) (int)x.size()
#define PB push_back
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef vector<int> vi;
const int INF=1e9+7;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
 
vector<vi> adj; 
vector<bool> visited;
vi dist;
int mayor, pos, n;
 
void dfs(int u){
    visited[u]=true;
    for(int& v: adj[u]){
        if(!visited[v]){
            dist[v]=dist[u]+1;
            if(mayor<dist[v]){
                mayor=dist[v];
                pos=v;
            }
            dfs(v);
        }
    }
}
 
void solve(int x){
    visited.assign(n+1,false);
    dist.assign(n+1,0);
    dfs(x);
}
 
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int u, v; cin >> n;
    if(n==1) cout << 0;
    else{
        adj.assign(n+1,vi());
        mayor=0; pos=-1;
        forx(i,n-1){
            cin >> u >> v;
            adj[u].PB(v);
            adj[v].PB(u);
        }
        solve(1);
        mayor=0;
        solve(pos);
        vi dist1=dist;
        solve(pos);
        for(int i=1; i<=n; i++) cout << max(dist[i],dist1[i]) << " ";
    }
    return 0;
}