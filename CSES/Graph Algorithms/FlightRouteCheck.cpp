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
    int n, m, a, b; cin >> n >> m;
    vii adj(n);
    vii adj1(n);
    p.assign(n,-1);
    for(int i=0; i<m; ++i){
        cin >> a >> b; a--; b--;
        adj[a].PB({b,1});
        adj1[b].PB({a,1});
    }
    vl dist0=dijkstra(0,n,adj);
    bool f=true;
    for(int i=1; i<n; i++){
        if(p[i]<0){
            cout << "NO\n 1 " << i+1;
            f=false;
            break;
        } 
    }
    if(f){
        p.assign(n,-1);
        vl dist1=dijkstra(0,n,adj1);
        for(int i=1; i<n; i++){
            if(p[i]<0){
                cout << "NO\n" << i+1 << " 1";
                f=false;
                break;
            } 
        }
    }
    if(f) cout << "YES";
    return 0;
}