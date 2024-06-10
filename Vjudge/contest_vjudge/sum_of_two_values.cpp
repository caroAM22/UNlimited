#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using s = set<ll>;
using m = map<ll, ll>;
#define forx(i,n) for(ll i=0; i<(ll)n; ++i)

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n, x, a;
    cin >> n >> x;
    m dict;
    s r;
    forx(i, n){  
        cin >> a;
        ll res=x-a;
        if(r.count(a)){   
            cout << dict[res] << " " << i+1; 
            return 0;
        }else{
            r.insert(res); 
        }
        dict.insert({a, i+1});
    }
    cout << "IMPOSSIBLE";
    return 0;
}