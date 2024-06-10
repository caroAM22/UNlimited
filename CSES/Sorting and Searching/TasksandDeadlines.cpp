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


int main(){
    int n, a, d; cin >> n;
    vi v;
    for(int i=0; i<n; ++i){
        cin >> a >> d;
        v.PB({a,d});
    }
    sort(all(v));
    ll time=0;
    ll reward=0;
    for(int i=0; i<n; ++i){
        time+=v[i].F;
        reward+=(v[i].S-time);
    }
    cout << reward;
    return 0;
}