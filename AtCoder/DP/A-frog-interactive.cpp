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
    memo[1]=0;
    memo[0]=0;
    for(int i = 2; i < n; i++) {
        ll d2=abs(costo[i-2]-costo[i])+memo[i-1];
        ll d1=abs(costo[i-2]-costo[i-1])+memo[i-2];
        memo[i]=min(d1, d2);
    }
    return memo[n];
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