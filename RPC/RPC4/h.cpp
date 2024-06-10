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
    int n, m, a, b, w; cin >> n >> m;
    char c;
    vii adj(n);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c >> w; a--; b--;
        if(c=='r') w=-w;
        adj[a].PB({b,w});
    }
    vl dist=dijkstra(0,n, adj);
    for(int i=1; i<n; ++i){
        if(dist[i]<0){
            cout << i+1 << "\n";
        }
    }
    return 0;
}