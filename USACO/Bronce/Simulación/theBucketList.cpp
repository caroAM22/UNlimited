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
typedef priority_queue<int> pi;
typedef map<int,int> mi;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n; cin >> n;
    int s, t, b;
    vi v(1000,0);
    int bal=0;
    forx(i,n){
        cin >> s >> t >> b;
        for(int j=s; j<=t; j++){
            v[j]+=b;
            bal=max(v[j],bal);
        }
    }
    cout << bal;
    return 0;
}