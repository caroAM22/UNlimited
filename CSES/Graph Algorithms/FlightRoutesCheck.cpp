#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define S second
#define F first
#define sz(x) ((int) x.size())
vector<bool> visited;
vector<bool> visited2;
vector<vector<int>> adj;
vector<vector<int>> adj1;

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

void bf2(int x){
    queue<int> q;
    q.push(x);
    visited2[x] = true;
    while(!q.empty()){
        int s=q.front(); q.pop();
        for(int u: adj1[s]){
            if(visited2[u]) continue;
            visited2[u]=true;
            q.push(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int a, b;
    cin >> n >> m;
    visited.assign(n+1,false);
    visited2.assign(n+1,false);
    adj.assign(n+1,vector<int>());
    adj1.assign(n+1,vector<int>());
    vector<int> res;
    for(int i=0; i<m; ++i){
        cin >> a >> b;
        adj[a].PB(b);
        adj1[b].PB(a);
    }
    int x=0;
    bfs(1);
    bool f=true;
    for(int i=2; i<n+1; ++i){
        if(!visited[i]){
            bfs(i);
            x=i;
            f=false;
            cout << "NO\n1 " << x;
        }
        if(!f) break;
    }
    if(f){
        f=true;
        bf2(1);
        for(int i=2; i<n+1; ++i){
            if(!visited2[i]){
                bf2(i);
                x=i;
                f=false;
                cout << "NO\n" << x << " " << 1;
            }
            if(!f) break;
        }
    }
    if(f) cout << "YES";
    return 0;
}