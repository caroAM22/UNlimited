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
const int INF = 1e9+7;

vi coin;
vi memo;

int solve(int n){
    memo[0] = 0;
    for (int x = 1; x <= n; x++) {
        memo[x] = INF;
        for (auto c : coin) {
            if (x - c >= 0) {
               memo[x] = min(memo[x], memo[x - c] + 1);
            }
        }
    }
    return memo[n];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, x; cin >> n >> x; 
    coin.assign(n,0);
    memo.assign(x+1,-1);
    forx(i,n) cin >> coin[i];
    int ans=solve(x);
    if(ans==INF) cout << -1;
    else cout << memo[x];
    return 0;
}