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
const int INF = -1e9+7;

vi a, b, c;
vector<vl> memo;

ll solve(int n, int k){
    if(n<0) return 0;
    
    if (memo[n][k] != -1) return memo[n][k];

    ll d1=0; ll d2=0; ll d3=0;
    if(k!=1) d1=a[n]+solve(n-1,1);
    if(k!=2) d2=b[n]+solve(n-1,2);
    if(k!=3) d3=c[n]+solve(n-1,3);
    ll ans=max(d1,max(d2,d3));

    memo[n][k]=ans;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    a.assign(n,0); b.assign(n,0); c.assign(n,0);
    memo.assign(n,vl(4,-1));
    forx(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << solve(n-1,0);
    return 0;
}