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

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    // freopen("paintbarn.in", "r", stdin);
    // freopen("paintbarn.out", "w", stdout);
    int n, k, a, b, a1, b1; cin >> n >> k;
    vector<vector<int>> f(11,vector<int>(11,0));
    ll ks=0; ll ant;
    for(int i=0; i<n;++i){
        cin >> a >> b >> a1 >> b1;
        f[a1][b1]++;
    }
    for(int i=1; i<11;++i){
        for(int j=1; j<11;++j){
            f[i][j]=f[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    for(int i=0; i<11;++i){
        print(f[i]);
    }
    cout << ks;
    return 0;
}