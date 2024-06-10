#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout << "\n"
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
typedef priority_queue<int> pi;
typedef map<int,int> mi;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k, a, b; cin >> n >> k;
    vi v(n);
    forx(i,n) cin >> v[i];
    int res=0;
    forx(i,n-1){
        stack<int> p;
        p.push(v[i]);
        for(int j=i+1;j<n;j++){
            if (abs(v[j]-p.top())<=k){
                p.push(v[j]);
            }
        }
        res=max(res,sz(p));
    }
    cout << res;
    return 0;
}