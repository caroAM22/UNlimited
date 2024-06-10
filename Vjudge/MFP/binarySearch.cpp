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

vl v; 

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    ll n, q, a; cin >> n >> q;
    forx(i,n){
        cin >> a; 
        v.PB(a);
    }
    forx(i,q){
        cin >> a; 
        auto it=lower_bound(all(v), a);
        if (it != v.end() && *it==a) cout << it - v.begin() << "\n";
        else cout << "-1\n";
    }
    return 0;
}