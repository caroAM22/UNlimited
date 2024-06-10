#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
#define PB push_back
#define S second
#define F first
#define sz(x) ((int) x.size())
#define forx(i,n) for(int i=0; i<(int)n; ++i)
vector<bool> visited;
vector<vector<ll>> adj;

ll n, m, x1;
ll target,menor;

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty()){
        int s=q.front(); q.pop();
        if(menor>abs(target-(ll)s)){
            menor=abs(target-(ll)s);
            x1=s;
        }
        for(int u: adj[s]){
            if(visited[u]) continue;
            visited[u]=true;
            q.push(u);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    ll t; cin >> t;
    ll a, b;
    forx(j,t){
        cin >> n >> m;
        visited.assign(n+1,false);
        adj.assign(n+1,vector<ll>());

        for(int i=0; i<m; ++i){
            cin >> a >> b;
            adj[a].PB(b);
            adj[b].PB(a);
        }
        set<ii> s;
        target=n;
        for(int i=1; i<n+1; ++i){
            if(!visited[i]){
                menor=INT_MAX;
                bfs(i);
                if(i!=x1 || i==1 || i==n) s.insert({i,x1});
            }
        }
        if(sz(s)==1) cout << 0;
        else if(sz(s)==2){
            auto it=s.begin();
            ii a1=*it;
            it++;
            ii b1=*it;
            ll cs1=1+pow(a1.S+1-b1.F,2);
            ll cs2=1+pow(a1.S-b1.F-1,2);
            cout << min(cs1,cs2);
        }
        else if(sz(s)==3){
            auto it=s.begin();
            ii a1=*it;
            it++;
            ii b1=*it;
            it++;
            ii c1=*it;
            cout << pow(a1.S-b1.F,2)+pow(b1.S-c1.F,2);
        }
        else if(sz(s)==4){
            auto it=s.begin();
            ii a1=*it;
            it++;
            ii b1=*it;
            it=s.end(); it--;
            ii c1=*it;
            it--;
            ii d1=*it;
            ll cos1=pow(a1.S-b1.F,2)+pow(b1.S-c1.F,2);
            ll cos2=pow(a1.S-d1.F,2)+pow(c1.F-d1.S,2);
            cout << min(cos1,cos2);
        }else{
            ll maxi=0;
            ll y1;
            for(auto x: s){
                if(x.F!=1 && x.S!=n){
                    if(maxi<x.S-x.F){
                        maxi=x.S-x.F;
                        x1=x.F; y1=x.S;
                    }
                }
            }
            auto it=s.begin();
            ii a1=*it;
            ii b1=*prev(s.end());
            cout << pow(a1.S-x1,2)+pow(b1.S-y1,2);
        }
        cout << "\n";
    }
    return 0;
}