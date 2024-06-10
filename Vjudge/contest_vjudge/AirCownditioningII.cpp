#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using  vl = vector<ll>;
using  vi = vector<int>;
using t = tuple<int, int, ll, int>;
using  t2 = tuple<int, int, ll>;
using vt = vector<t>;
using  v = vector<t2>;
using pbi = pair<bool, int>;
#define forx(i, n) for (int i = 0; i < n; i++)
#define pb push_back

pbi valid(vt& sub, v& cow){
    ll sum = 0;
    vi stalls(101,0);
    forx(i, sub.size()){
        for (int j = get<0>(sub[i]); j <= get<1>(sub[i]); j++){
            stalls[j] += get<2>(sub[i]);
        }
        sum = sum + get<3>(sub[i]);
    }
    forx(i, cow.size()){
        for (int j = get<0>(cow[i]); j <= get<1>(cow[i]); j++){
            if (stalls[j] < get<2>(cow[i])) return {false, 0};
        }
    }
    return {true, sum};
}

ll subsets(vt& a, v& cow){
    ll res=0;
    for (int i=0; i<(1<<a.size()); ++i){  
        vt subset;
        for (int j=0; j<a.size(); ++j){
            if (i & (1<<j)) subset.pb(a[j]);
        }
        pbi val=valid(subset, cow);
        if (val.first && (res==0 || val.second<res)){
            res=val.second;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m, a, b, c, s, t;
    ll p;
    cin >> n >> m;
    vt air;
    v cow;
    forx(i,n){
        cin >> s >> t >> c;
        cow.pb({s, t, c});
    }
    forx(i,m){
        cin >> a >> b >> p >> c;
        air.pb({a, b, p, c});
    }
    
    cout << subsets(air, cow);

    return 0;
}