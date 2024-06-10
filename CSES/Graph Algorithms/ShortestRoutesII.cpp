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
const ll INF = 1e18;

vector<vl> adj;  
vector<vl> dist;   
int n, m;   

void floydWarshall(){
    forx(k,n) {
        forx(i,n) {
            forx(j,n) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int q, a, b; cin >> n >> m >> q;
    ll w;
    adj.assign(n, vl(n));
    dist.assign(n, vl(n)); 
    forx(i,m){
        cin >> a >> b >> w; a--; b--;
        if(adj[a][b]){
            adj[a][b]=min(w,adj[a][b]);
            adj[b][a]=min(w,adj[b][a]);
        }else{
            adj[a][b]=w;
            adj[b][a]=w;
        }
    }
    forx(i,n) {
        forx(j,n) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }
    floydWarshall();
    forx(i,q){
        cin >> a >> b;
        a--; b--;
        if(dist[a][b]==INF) cout << -1;
        else cout << dist[a][b];
        cout << "\n";
    }
    return 0;
}