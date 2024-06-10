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
    int t, n, m, num; cin >> t;
    forx(i,t){
        cin >> n;
        vi a(n), b(n);
        forx(j,n) cin >> a[j];
        map<int, vi> s;
        set<int> s1;
        forx(j,n) {
            cin >> b[j];
            if(a[j]!=b[j]){
                s[b[j]].PB(j);
            }
            s1.insert(b[j]);
        }
        cin >> m;
        bool ba=false;
        vi d(m);
        multiset<int> s2;   
        forx(j,m){
            cin >> d[j];
            s2.insert(d[j]);
        }
        //  for(auto x: s){
        //     cout << x.F << "\n";
        //     for(auto y: x.S) cout << y << " ";
        //     cout << "\n";
        // }
        forx(j, m) {
            int num = d[j];
            auto it = s2.find(num);
            if (it != s2.end()) {
                s2.erase(it);
            }
            if (s.count(num)) {
                vi &v = s[num];
                a[v[0]] = num;
                v.erase(v.begin());
                if (v.empty()) {
                    s.erase(num);
                }
            } else if (s1.count(num)) {
                continue;
            } else {
                if (!s.empty()) {
                    continue;
                } else if (j == m-1) {
                    ba = true;
                } else {
                    bool f = true;
                    for (auto x : s2) {
                        if (s1.count(x)) {
                            f = false;
                            break;
                        }
                    }
                    if (f) ba = true;
                }
            }
        }
        if(ba || (sz(s)>0)) cout << "NO\n";
        else cout << "YES\n";
        // for(auto x: s){
        //     cout << x.F << "\n";
        //     for(auto y: x.S) cout << y << " ";
        //     cout << "\n";
        // }
    }
    return 0;
}
