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
    int n, q, a, b; cin >> n >> q;
    vl v(n+1);
    cin >> v[1];
    for(int i=2; i<=n; i++){
        cin >> v[i];
        v[i]=v[i]^v[i-1];
    }
    forx(i,q){
        cin >> a >> b; 
        cout << (v[a-1]^v[b]) << "\n";
    }
    return 0;
}