#include <bits/stdc++.h>
using namespace std;

#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n";
#define all(x) x.begin(), x.end()
#define PB push_back
#define S second
#define F first
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef pair<int, int> ii;
typedef vector<ll> vl;
typedef vector<int> vi;
const ll INF = 1e18;

vector<vector<ii>> adj;   
vi p;
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
                p[b]=u;
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
    p.assign(n,-1);
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c; a--; b--;
        adj[a].PB({b,c});
        adj[b].PB({a,c});
    }
    dijkstra(1);
    print(p);
    int i=1;
    if(p[i]==-1) cout << -1;
    else{
        print(p);
        vi path={2};
        while(i!=3){
            path.PB(p[i]+1);
            i=p[i]; 
        }
        reverse(all(path));
        print(path);
    }
    return 0;
}