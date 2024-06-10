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
typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef vector<ii> vii;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, x; cin >> n;
    for(int i=0; i<n; i++){
        vi v;
        for(int j=0; j<4; j++){
            cin >> x;
            if(j<2) v.PB({x,1});
            else v.PB({x,2});
        }
        sort(all(v));
        if(v[0].S==v[2].S) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}