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
    forx(i,k+1) memo[i][0]=0;
    forx(i,n+1) memo[0][i]=0;

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            ll d1 = 0;
            if(i >= peso[j-1]) {
                d1 = valor[j-1] + memo[i - peso[j-1]][j-1];
            }
            ll d2 = memo[i][j-1];
            memo[i][j] = max(d1, d2);
        }
    }
    return memo[k][n];
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