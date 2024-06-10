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

ll binpow(ll a, ll b, ll m){  
	ll res=1;a%=m;
	while(b>0){
		if(b&1)res=(res*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return res%m;
}

int main(){
    ll n; cin >> n;
    ll res=binpow(2,n,MOD);
    cout << res;
    return 0;
}