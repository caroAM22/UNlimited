#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
const int MOD = 1e9+7;

vl primos;
ll lon_criba;
vector<bool> is_prime;
void criba(ll n){
	lon_criba=n;
	is_prime.assign(n+1,true);
	for(ll i=2;i<=n;++i){
		if(!is_prime[i])continue;
		for(ll j=1ll*i*i;j<=n;j+=i)is_prime[j]=false;
		primos.PB(i);
	}
}

ll binpow(ll a, ll b, ll m){  
	ll res=1;a%=m;
	while(b>0){
		if(b&1)res=(res*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return res%m;
}

void primeFactors(ll n, map<ll,int>& f){
	for(int i=0;i<sz(primos) && 1ll*primos[i]*primos[i]<=n;++i)
		while(n%primos[i]==0){
			f[primos[i]]++;
			n/=primos[i];
		}
	if(n>1)f[n]++; 
}  

// d(n) = (a1+1)*(a2+1)*...*(ak+1)
ll numDiv(ll n){
    ll ans=1;
    map<ll, int> f;
    primeFactors(n,f);
    for(auto &x:f)ans*=(x.S+1);
    return ans;
}

ll sumDiv(map<ll, int>& f){
    ll ans=1;
    for(auto &x:f)
        ans*=(binpow(x.F,x.S+1,MOD)-1)/(x.F-1);
    return ans;
}

ll productDiv(map<ll, int>& f){
    ll pi=1,res=1;
    for(auto x:f){
        ll p=binpow(x.F, x.S*(x.S+1)/2,MOD);
        res=(binpow(res, x.S+1,MOD)*binpow(p, pi,MOD))%MOD;
        pi=(pi*(x.S+1))%(MOD-1);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n;
    ll x, k;
    cin >> n;
    map<ll, int> f;
    ll num=1;
    for(int i=0; i<n; i++){
        cin >> x >> k;
        f[x] += k;
        num=(num*(k+1))%MOD;
    }
    ll sum = sumDiv(f);
    ll pro = productDiv(f);
    cout << num << " " << sum << " " << pro;
    return 0;
}