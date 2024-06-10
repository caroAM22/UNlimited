#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=1; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
const int MOD = 1e9+7;

vl p;
ll lon_criba;
vector<bool> is_prime;
void criba(ll n){
	lon_criba=n;
	is_prime.assign(n+1,true);
	for(ll i=2;i<=n;++i){
		if(!is_prime[i])continue;
		for(ll j=1ll*i*i;j<=n;j+=i)is_prime[j]=false;
		p.PB(i);
	}
}

long long sumDiv(long long N) {
  long long ans = 1;
  for (int i = 0; i < (int)p.size() && (p[i] * p[i] <= N); ++i) {
    long long multiplier = p[i]; long long total = 1;
    while (N % p[i] == 0) {
      N /= p[i];
      total += multiplier;
      multiplier *= p[i];
    }
    ans *= total;
  }
  if (N != 1) ans *= (N + 1); 
  return ans;
}

int main(){
    ll n; cin >> n;
    criba(n);
    ll sum=0;
    forx(i,n+1){
        sum=(sum%MOD+sumDiv(i)%MOD)%MOD;
    }
    cout << sum;
    return 0;
}