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

vector<int> visited;
vector<vector<int>> adj;

int n, k; 

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = k;
    while(!q.empty()){
        int s=q.front(); q.pop();
        for(int u: adj[s]){
            if(visited[u]!=0) continue;
            visited[u]=k;
            q.push(u);
        }
    }
}

bool dist(int x1, int y1, int x2, int y2, int d){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2)) > d; 
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int a, b, q, d;
    cin >> n >> q >> d;
    set<ii> s;
    map<ii, int> m;
    visited.assign(n+1,0);
    adj.assign(n+1,vector<int>());
    forx(i,n){
        cin >> a >> b;
        s.insert({a,b});
        m[{a,b}]=i+1;
    }
    set<ii> s1;
    for(auto &u: s){
        for(int i=d; i>=-d; --i){
            for(int j=d; j>=-d; --j){
                int x=u.F; int y=u.S;
                if((i==0 && j==0) || (dist(x,y,x+j,y+i,d))) continue;
                if(s.count({x+j,y+i}) && !s1.count({m[{x+j,y+i}],m[{x,y}]})){
                    adj[m[{x,y}]].PB(m[{x+j,y+i}]);
                    adj[m[{x+j,y+i}]].PB(m[{x,y}]);
                    s1.insert({m[{x,y}],m[{x+j,y+i}]});
                    s1.insert({m[{x+j,y+i}],m[{x,y}]});
                }
            }
        }
    }
    k=1;
    for(int i=1; i<n+1; ++i){
        if(visited[i]==0){
            bfs(i);
            k++;
        }
    }
    forx(i,q){
        cin >> a >> b;
        if(visited[a]==visited[b]) cout << "S\n";
        else cout << "N\n";
    }
    return 0;
}