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

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int n, x, a, t, b; cin >> x >> n;
    set<int> lights = {0, x};
    set<ii> s{{0,x}};
    map<int,set<ii>> m{{x,s}}; 
    for(int i=0; i<n; ++i){
        cin >> t;
        auto it=lights.lower_bound(t);
        a=*it; it--; 
        b=*it;
        m[a - b].erase({b, a});
        if (m[a - b].empty()) {
            m.erase(a - b);
        }
        if (a - t != 1 || (a - t == 1 && a != x)) {
            m[a - t].insert({t, a});
        }
        
        if (t - b != 1 || (t - b == 1 && b != 0)) {
            m[t - b].insert({b, t});
        }
        cout << prev(m.end())->F << " "; 
        lights.insert(t);
    }
    return 0;
}
