#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MOD = 1e9+7;
 
vector<bool> visited;
vi dist;
vector<vi> adj;
 
ii mayor={0,1};
 
void dfs(int x){
    visited[x] = true;
    for(int u: adj[x]){
        if (!visited[u]) {
            dist[u] = dist[x] + 1;
            if(dist[u]>mayor.F){
                mayor={dist[u],u};
            }
            dfs(u);
        }
    }
}
 
int main(){
    int n, a, b; cin >> n;
    adj.assign(n+1,vi());
    dist.assign(n+1, 0);
    visited.assign(n+1,false);
    forx(i,n-1){
        cin >> a >> b; 
        adj[a].PB(b);
        adj[b].PB(a);
    }
    dfs(1);
    b=mayor.S;
 
    dist.assign(n+1, 0);
    visited.assign(n+1,false);
    mayor={0,4};
 
    dfs(b);
    cout << mayor.F;
    return 0;
}