#include <bits/stdc++.h>
using namespace std;

#define PB push_back

vector<vector<int>> adj;
vector<bool> visited;
vector<int> teams;
int n, m, t;

string bfs(int x){
    queue<int> q;
    visited[x]=true;
    teams[x]=1;
    q.push(x);
    while(!q.empty()){
        int s=q.front(); q.pop();
        if(teams[s]==1) t=2;
        if(teams[s]==2) t=1;
        for(int u: adj[s]){
            if(visited[u] && teams[s]==teams[u]) return "IMPOSSIBLE";
            else if(visited[u] && teams[s]!=teams[u]) continue;
            visited[u]=true;
            teams[u]=t;
            q.push(u);
        }
    }
    return "";
}

int main(){
    cin >> n >> m;
    int a, b;
    adj.assign(n+1, vector<int>());
    visited.assign(n+1,false);
    teams.assign(n+1,0);
    for(int i=0; i<m; ++i){
        cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    string res;
    bool f=true;
    for(int i=1; i<n+1; ++i){
        if(!visited[i]){
            res=bfs(i);
            if (res=="IMPOSSIBLE"){
                f=false;
                break;
            }
        }
    }
    if(f){
        for(int i=1; i<n+1; ++i) cout << teams[i] << " ";
    }else{
        cout << "IMPOSSIBLE";
    }
    return 0;
}