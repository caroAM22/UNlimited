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

vi valor;
vi peso;

vector<vl> memo;

ll solve(int k, int n){
    if(k==0) return 0;
    if(n==0) return 0;
    
    if (memo[k][n] != -1) return memo[k][n];

    ll d1=0;
    if(k>=peso[n-1]) d1=valor[n-1]+solve(k-peso[n-1],n-1);
    ll d2=solve(k,n-1);
    ll ans=max(d1,d2);
    
    memo[k][n]=ans;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, k; cin >> n >> k;
    peso.assign(n,0);
    valor.assign(n,0);
    memo.assign(k+1,vl(n+1,-1));
    forx(i,n){
        cin >> peso[i];
        cin >> valor[i];
    }
    cout << solve(k,n);
    return 0;
}