#include <bits/stdc++.h>
using namespace std;

#define print(arr) for(auto& x:arr)cout<<x<<" ";
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
			}
		}
	}
    return dist;
}

int main(){
    int n, m, a, b, x, y, w; cin >> n >> m >> x >> y;
    x--; y--;
    vii adj(n);
    vii edges(n); 
    for(int i=0; i<m; ++i){
        cin >> a >> b >> w; a--; b--;
        adj[a].PB({b,w});
        adj[b].PB({a,w});
        edges[a].PB({b,w});
    }
    vl distA=dijkstra(x,n,adj);
    vl distB=dijkstra(y,n,adj);
    ll dm=distA[y];
    ll cont=0;
    for(int i=0; i<n; ++i){
        a=i;
        for(auto &v: edges[i]){
            b=v.F; w=v.S;
            ll dab=distA[a]+w+distB[b];
            ll dba=distA[b]+w+distB[a];
            if(dm!=(min(dab,dba))){
                cont+=w;
            }
        }
    }
    cout << cont;
    return 0;
}