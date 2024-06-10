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
vector<vi> adj;
vi distancia;

int n, m; 

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    distancia[x]=0;
    while(!q.empty()){
        int s=q.front(); q.pop();
        for(int u: adj[s]){
            if(visited[u]) continue;
            distancia[u]=distancia[s]+1;
            visited[u]=true;
            q.push(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
    visited.assign(f+1,false);
    adj.assign(f+1,vi());
    distancia.assign(f+1,-1);
    for(int i=1; i<=f; ++i){
        if(i+u<=f) adj[i].PB(i+u);
        if(i-d>=1) adj[i].PB(i-d);
    }
    bfs(s);
    if(visited[g]) cout << distancia[g];
    else cout << "use the stairs";
    return 0;
}