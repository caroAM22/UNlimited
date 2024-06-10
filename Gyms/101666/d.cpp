#include <bits/stdc++.h>
using namespace std;
 
#define sz(x) ((int) x.size())
#define all(x) x.begin(), x.end()
#define print(arr) for(auto& x:arr)cout<<" "<<x;cout<<"\n";
#define PB push_back
#define F first
#define S second
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef pair<ll, int> pli;
typedef vector<pli> vli;
typedef vector<vector<ii>> vii;
const ll INF=1e18;
 
vector<int> p;
set<ii> edges;
 
vl dijkstra(int s, int n, vii &adj){
    priority_queue<pli, vli, greater<pli>> pq;
    vl dist(n,INF);
	pq.push({0, s});
	dist[s]=0;
	while(!pq.empty()){
		pli act=pq.top();pq.pop();
		ll d=act.F;
        int u=act.S;
		if(d>dist[u])continue;
		for(auto v:adj[u]){
			int w=v.S,b=v.F;
			if(dist[u]+w<dist[b]){
				dist[b]=dist[u]+w;
				pq.push({dist[b],b});
                p[b]=u;
			}
		}
	}
    return dist;
}
 
int main(){
    int n, m, a, b, w; cin >> n >> m;
    vii adj(n);
    p.assign(n,-1);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> w;
        adj[a].PB({b,w});
        adj[b].PB({a,w});
    }
    vl dist0=dijkstra(1,n,adj);
    for(int i=0; i<n; i++){
        if(i==1) continue;
        for(int j=0; j<sz(adj[p[i]]); ++j){
            if(adj[p[i]][j].F==i){
                adj[p[i]].erase(adj[p[i]].begin()+j);
            }
        }
    }
    p.assign(n,-1);
    dist0=dijkstra(1,n,adj);
    int i=0;
    if(p[i]==-1) cout << "impossible";
    else{
        vector<int> path={0};
        while(i!=1){
            path.PB(p[i]);
            i=p[i]; 
        }
        cout << sz(path);
        print(path);
    }
    return 0;
}