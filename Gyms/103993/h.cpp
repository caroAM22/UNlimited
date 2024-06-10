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
    int n, p; cin >> n >> p;
    set<ii> v;
    forx(i,n){
        int a, b; cin >> a >> b;
        ii new_interval = {a, b};
        auto it = v.lower_bound({a, b});
        while (it != v.end() && it->first <= b) {
            new_interval.first = min(new_interval.first, it->first);
            new_interval.second = max(new_interval.second, it->second);
            it = v.erase(it); 
        }
        if (it != v.begin()) {
            it--;
            if (it->second >= a) {
                new_interval.first = min(new_interval.first, it->first);
                new_interval.second = max(new_interval.second, it->second);
                v.erase(it);
            }
        }
        v.insert(new_interval);
    }
    auto it=v.begin();
    int s=0; int t=0;
    if(it->F!=1){
        s=1;
        t=it->F-1;
    }
    for(it; it!=prev(v.end()); ++it){
        auto nt=next(it);
        if(nt->F-it->S>1){
            if(s!=0){
                t=nt->F-1;
            }else{
                s=it->S+1;
                t=nt->F-1;
            }
        }
    }
    it=prev(v.end());
    if(it->S!=p){
        if(s!=0){
            t=p;
        }else{
            s=it->S+1;
            t=p;
        }
    }
    if(t==0 && s==0) cout << 0;
    else cout << t-s+1;
    return 0;
}