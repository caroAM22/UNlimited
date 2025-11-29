// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
#define forx(i,n) for(int i=0; i<(int)n; ++i)
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define PB push_back
#define sz(x) ((int) x.size())
typedef vector<int> vi;
 
vector<vi> adj;
set<int> match;
 
void dfs(int u, int p){
    for(int& v: adj[u]){
        if(v!=p){
            dfs(v,u);
            if(match.count(v)==0 && match.count(u)==0){
                match.insert(u);
                match.insert(v);
            }
        }
    }
}
 
int main() {
	int n,u,v; cin >> n;
    adj.assign(n+1,vi());
    forx(i,n-1){
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    dfs(1,-1);
    cout << sz(match)/2;
}