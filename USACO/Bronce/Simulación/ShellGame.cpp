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
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n, a, b, q; cin >> n;
    int uno=0; int dos=0; int tres=0;
    vi v{1,2,3};
    for(int i=0; i<n; i++){
        cin >> a >> b >> q;
        swap(v[a-1], v[b-1]);
        if (v[q-1]==1)uno+=1;
        else if (v[q-1]==2)dos+=1;
        else tres+=1;
    }
    cout << max({uno,dos,tres});
    return 0;
}