#include <bits/stdc++.h>
using namespace std;

#define print(arr) for(auto x:arr)cout<<x<<" ";cout<<"\n"
#define sz(x) ((int) x.size())
#define PB push_back 

typedef long long ll;
typedef vector<ll> vl;

// O(n*log(log(n)))
vl p;
ll lon_criba;
int len;
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

string primos_relativos(){
  ll a, n; cin >> n;
  bool b=false;
  set<ll> s;
  for(int j=0; j<n; j++){
      cin >> a;
      if(b)continue;
      for(int i=0; i<len; i++){
        if(a<p[i] || p[i]*p[i]>a){
          break;
        }
        if(a%p[i]!=0)continue;
        while(a%p[i]==0)a/=p[i];
        if(s.count(p[i])){
          b=true;
          break;
        }else s.insert(p[i]);
      }
      if(a!=1){
        if(s.count(a)) b=true;
        else s.insert(a);
      }
  }
  if(b) return "YES";
  return "NO";
}

int main(){
    int t; cin >> t;
    criba(1000000);
    len=sz(p);
    for(int i=0;i<t;i++){
        cout << primos_relativos() << "\n";
    }
    return 0;
}