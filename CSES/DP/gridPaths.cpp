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

vector<vector<char>> mapa;
vector<vi> memo;

ll solve(int x, int y){
    if (x < 1 || y < 1) return 0;
    if(mapa[x-1][y-1]=='*') return 0;
    if (x == 1 && y == 1) return 1;

    if (memo[x][y] != -1) return memo[x][y];
    
    ll d1=solve(x-1,y);
    ll d2=solve(x,y-1);

    memo[x][y] = (d1+d2)%MOD;
    return memo[x][y];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n; 
    forx(i,n){
        vector<char> v(n);
        forx(j,n){
            cin >> v[j];
        }
        mapa.PB(v);
    }
    memo.assign(n+1,vi(n+1,-1));
    forx(i,n+1) memo[i][0]=0;
    forx(i,n+1) memo[0][i]=0;
    cout << solve(n,n);
    return 0;
}