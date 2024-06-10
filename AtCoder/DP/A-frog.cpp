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

vi costo;
vl memo;

ll solve(int n){
    if(n==1) return 0;
    
    if (memo[n] != -1) return memo[n];

    ll d2=INT_MAX;
    ll d1=abs(costo[n-1]-costo[n-2])+solve(n-1);
    if(n-3>=0) d2=abs(costo[n-1]-costo[n-3])+solve(n-2);
    ll ans=min(d1,d2);
    memo[n]=ans;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    costo.assign(n,0);
    memo.assign(n+1,-1);
    forx(i,n) cin >> costo[i];
    cout << solve(n);
    print(memo);
    return 0;
}