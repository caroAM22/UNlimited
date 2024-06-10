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
const ll INF = 1e18;

vl valor;
vl peso;

vector<vl> memo;

ll solve(int k, int n, ll valorTotal){
    memo[0][0] = 0;
    ll ans=0;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=valorTotal; ++j){
           if(memo[i-1][j]!=INF && memo[i][j]==INF) memo[i][j] = memo[i-1][j];
           if(memo[i][j]!=INF){
               memo[i][j+valor[i-1]]=min(memo[i-1][j+valor[i-1]], memo[i-1][j]+peso[i-1]);
           }
        }
    }
    forx(i,valorTotal+1){
        if(memo[n][i]<=k) ans = i;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, k; cin >> n >> k;
    peso.assign(n,0);
    valor.assign(n,0);
    ll valorTotal = 0;
    forx(i,n){ 
        cin >> peso[i];
        cin >> valor[i];
        valorTotal+=valor[i];
    }
    memo.assign(n+1,vl(valorTotal+1,INF));
    cout << solve(k,n, valorTotal);
    return 0;
}