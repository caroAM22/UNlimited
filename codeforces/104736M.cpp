#include <bits/stdc++.h>
using namespace std;
 
#define sz(x) ((int) x.size())
#define all(x) x.begin(), x.end()
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n";
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
    int n, m, a, b, w, pe, g; 
    cin >> n >> m >> pe >> g; 
    pe--; g--;
    vii adj(n);
    p.assign(n,-1);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> w; a--; b--;
        adj[a].PB({b,w});
        adj[b].PB({a,w});
    }
    vl distG=dijkstra(g,n,adj);
    vector<int> pg=p;
    p.assign(n,-1);
    vl distP=dijkstra(pe,n,adj);
    bool f=false;
    for(int i=0; i<n; ++i){
        if(i==pe || i==g) continue;
        if(distP[g]==distG[i] && distP[i] == distP[g] + distG[i]){
            int j=i;
            vector<int> path={j+1};
            while(j!=pe){
                path.PB(p[j]+1);
                j=p[j]; 
            }
            if(sz(path)%2!=0 && path[sz(path)/2]==g+1){
                cout << i+1 << " ";
                f=true;
            }else if(path[sz(path)/2]==g || path[(sz(path)/2)+1]==g+1){
                cout << i+1 << " ";
                f=true;
            }
        }
    }
    if(!f) cout << "*";
    return 0;
}