#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

ll mod = 1e9+7;
#define forx(i,n) for(int i=0; i<(int)n; ++i)

int binpow(){
    ll a, b;
    cin >> a >> b;
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a=(a*a)%mod;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    forx(i, n) cout << binpow() << "\n";
    return 0;
}