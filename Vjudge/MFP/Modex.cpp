#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
#define forx(i,n) for(int i=0; i<(int)n; ++i)

int binpow(ll a, ll b, ll MOD){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%MOD;
        a=(a*a)%MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll a, b, n, MOD;
    cin >> n;
    forx(i,n){
        cin >> a >> b >> MOD;
        cout << binpow(a,b,MOD) << "\n";
    }
    cin >> a;
    return 0;
}