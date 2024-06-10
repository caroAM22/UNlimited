#include <bits/stdc++.h>
using namespace std;

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
    int a,b;
    cin >> n >> m;
    while(n!=0 && m!=0){
        vector<ii> edges;
        adj.assign(n+1,vector<int>());

        for(int i=0; i<m; ++i){
            cin >> a >> b;
            edges.PB({a,b});
            adj[a].PB(b);
            adj[b].PB(a);
        }
        bool f1=false; 
        forx(j,m){
            a=edges[j].F; 
            b=edges[j].S;
            adj[a].erase(find(all(adj[a]),b));
            adj[b].erase(find(all(adj[b]),a));
            bool f=true;
            visited.assign(n+1,false);
            forx(i,n){
                if(!visited[i] && f){
                    bfs(i);
                    f=false;
                }else if(!visited[i]){
                    f1=true;
                    break;
                }
            }
            adj[a].PB(b);
            adj[b].PB(a);
            if(f1) break;
        }
        if(f1) cout << "Yes\n";
        else cout << "No\n";
        cin >> n >> m;
    }
    return 0;
}