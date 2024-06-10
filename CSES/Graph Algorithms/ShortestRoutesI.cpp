#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define S second
#define F first
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef pair<int, int> ii;
typedef vector<ll> vl;
const ll INF = 1e18;

vector<vector<pair<int, int>>> adj;   
vl dist;        
int n, m, s;

void dijkstra(int s){
	priority_queue<pll, vll, greater<pll>> pq;
	pq.push({0, s});
	dist[s]=0;
	while(!pq.empty()){
		pll act=pq.top();pq.pop();
		ll d=act.F,u=act.S;
		if(d>dist[u])continue;
		for(auto v:adj[u]){
			int w=v.S,b=v.F;
			if(dist[u]+w<dist[b]){
				dist[b]=dist[u]+w;
				pq.push({dist[b],b});
			}
		}
	}
}

int main(){
    int a, b, c;
    cin >> n >> m;
    adj.assign(n, vector<ii>());
    dist.assign(n, INF); 
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c; a--; b--;
        adj[a].PB({b,c});
    }
    dijkstra(0);
    for(auto &x: dist){
        cout << x << " ";
    }
    return 0;
}