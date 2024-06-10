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

vi peso;

vector<vector<vi>> memo;
ll m1=0, m2=0;

ll solve(int c1, int c2, int n){
    if(n==0) return 0;

    if (memo[c1][c2][n] != -1) return memo[c1][c2][n];

    ll d1=0; ll d2=0;
    if(c1>=peso[n-1]) d1=peso[n-1]+solve(c1-peso[n-1],c2,n-1);
    if(c2>=peso[n-1]) d2=peso[n-1]+solve(c1,c2-peso[n-1],n-1);
    ll d3=solve(c1,c2,n-1);
    ll ans=max(d1,max(d2,d3));

    memo[c1][c2][n]=ans;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, k; cin >> n >> k;
    peso.assign(k,0);
    memo.assign(n+1,vector(n+1,vi(k+1,-1)));
    forx(i,k) cin >> peso[i];
    cout << solve(n,n,k);
    return 0;
}