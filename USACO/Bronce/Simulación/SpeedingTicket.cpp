#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<< " ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MOD = 1e9+7;

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, m, l, vel; cin >> n >> m;
    vi ca;
    vi va;
    forx(i,n){
        cin >> l >> vel; 
        forx(j,l) ca.PB(vel);
    }
    forx(i,m){
        cin >> l >> vel; 
        forx(j,l) va.PB(vel);
    }
    int res=0;
    forx(i, 100){
        res=max((va[i]-ca[i]),res);
    }
    cout << res;
    return 0;
}