#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<"\n";
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
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, a; cin >> n;
    vi patron, ids, cambio;
    forx(i,n){
        cin >> a;
        patron.PB(a);
    }
    forx(i,n){
        cin >> a;
        ids.PB(a);
    }
    forx(j,3){
        cambio.resize(0);
        forx(i,n){
            cambio.PB(ids[patron[i]-1]);
        }
        ids=cambio;
    }
    print(ids);
    return 0;
}