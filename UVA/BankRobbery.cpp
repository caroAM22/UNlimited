#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define PB push_back
#define F first
#define S second
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> ii;
typedef pair<ll, ll> pli;
typedef vector<pli> vli;
typedef vector<vector<ii>> vii;
const ll INF=1e18;

vl dijkstra(vl &policia, int n, vii &adj){
    priority_queue<pli, vli, greater<pli>> pq;
    vl dist(n,INF);
    for(ll &x: policia){
        pq.push({0, x});
	    dist[x]=0;
    }
	while(!pq.empty()){
		pli act=pq.top();pq.pop();
		ll d=act.F;
        ll u=act.S;
		if(d>dist[u])continue;
		for(auto v:adj[u]){
			ll w=v.S,b=v.F;
			if(dist[u]+w<dist[b]){
				dist[b]=dist[u]+w;
				pq.push({dist[b],b});
			}
		}
	}
    return dist;
}

int main(){
    ll n, m, b, p, v, u, w; 
    cin >> n;
    while(n!=-1){
        cin >> m >> b >> p;
        vii adj(n);
        for(int i=0; i<m; ++i){
            cin >> u >> v >> w;
            adj[u].PB({v,w});
            adj[v].PB({u,w});
        }
        vl policia, bancos;
        for(int i=0; i<b; ++i){
            cin >> u; 
            bancos.PB(u);
        }
        sort(all(bancos));
        for(int i=0; i<p; ++i){
            cin >> u;
            policia.PB(u);
        }
        vl dist=dijkstra(policia, n, adj);
        ll mayor=-1e18;
        vl distBP;
        for(int i=0; i<b; ++i){
            if(dist[bancos[i]]==mayor){
                distBP.PB(bancos[i]);
            }else if(dist[bancos[i]]>mayor){
                distBP={bancos[i]};
                mayor=dist[bancos[i]];
            }
        }
        cout << sz(distBP) << " ";
        if(mayor==INF) cout << "*\n";
        else cout << mayor << "\n";
        bool f1=false;
        for(auto &x: distBP){
            if(f1) cout << " " << x;
            else{
                cout << x;
                f1=true;
            }
        }
        cout << "\n";
        n=-1;
        cin >> n;
    } 
    return 0;
}