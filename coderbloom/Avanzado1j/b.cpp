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
const int mod = 1e9+7;

ll binpow(ll base, ll exp, ll mod){
    base=base%mod;
    ll res = 1;
    while(exp>0){
        if(exp&1) res = (res*base)%mod;
        base=(base*base)%mod;
        exp >>= 1;
    }
    return res;
}

ll inv(ll num, ll mod){
    return binpow(num,mod-2,mod);
}

ll factorial(ll n){
    ll factoriales=1;
    for(int i=1; i<=n; i++){
        factoriales=((factoriales*i)%mod);
    }
    return factoriales;
}

ll combinaciones(int n, int k) {
    if (k>n) return 0; 
    return (factorial(n)*inv((factorial(k)*factorial(n-k))%mod, mod))%mod;
}

int main() {
    int n, k; cin >> n >> k;
    cout << combinaciones(n, k);
    return 0;
}
