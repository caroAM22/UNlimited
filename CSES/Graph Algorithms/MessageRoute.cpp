#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define sz(x) ((int) x.size())
vector<bool> visited;
vector<vector<int>> adj;
vector<int> path;
vector<int> distancia;
vector<int> dad;
bool f=false;
int n, m;

bool bfs(int x){
    queue<int> q;
    visited[x]=true;
    q.push(x);
    distancia[x]=0;
    while(!q.empty()){
        int s=q.front(); q.pop();
        for(int u: adj[s]){
            if(visited[u]) continue;
            distancia[u]=distancia[s]+1;
            dad[u]=s;
            if(u==n){
                cout << distancia[u]+1 << "\n";
                while(u!=1){
                    path.PB(u);
                    u=dad[u];
                }
                return true;
            }
            visited[u]=true;
            q.push(u);
        }
    }
    return false;
}

int main(){
    int a, b; cin >> n >> m;
    adj.assign(n+1,vector<int>());
    visited.assign(n+1,false);
    distancia.assign(n+1,-1);
    dad.resize(n+1);
    bool f=false;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    f=bfs(1);
    if(f){
        cout << 1;
        for(int i=sz(path)-1; i>=0; i--){
            cout << " " << path[i];
        }
    }else cout << "IMPOSSIBLE";
    return 0;
}