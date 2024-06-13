//Exponenciación binaria
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

//Inverso modular 
ll inv(ll num, ll mod){
    return binpow(num,mod-2,mod);
}

//Criba O(n*log(log(n)))
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

ll binpow(ll a, ll b, ll m);
void primeFactors(ll n, map<ll, int>& f);

// d(n) = (a1+1)*(a2+1)*...*(ak+1)
ll numDiv(ll n){
    ll ans=1;
    map<ll, int> f;
    primeFactors(n,f);
    for(auto &x:f)ans*=(x.S+1);
    return ans;
}

// sigma(n) = (p1^(a1+1)-1)/(p1-1) * (p2^(a2+1)-1)/(p2-1) * ... * (pk^(ak+1)-1)/(pk-1)
ll sumDiv(ll n){
    ll ans=1;         
    map<ll, int> f;
    primeFactors(n,f);
    for(auto &x:f)
        ans*=(binpow(x.F,x.S+1,MOD)-1)/(x.F-1);
    return ans;
}

ll productDiv(map<int, ll>& f){
    // implementar binpow
    ll pi=1,res=1;
    for(auto x:f){
        ll p=binpow(x.F, x.S*(x.S+1)/2,MOD);
        res=(binpow(res, x.S+1,MOD)*binpow(p, pi,MOD))%MOD;
        pi=(pi*(x.S+1))%(MOD-1);
    }
    return res;
}

ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod(ll a, ll b) { return (((a % b) + b) % b); }
ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll suma(ll a, ll b){return mod(mod(a)+mod(b));}
ll mult(ll a, ll b){return mod(mod(a)*mod(b));}

//exponenciación matricial
const int nmax = 100; const ll MOD = 1e9+7;
struct matrix{
  int r, c;
  long long m[nmax][nmax];
  matrix (int r, int c): r(r), c(c) {memset(m, 0, sizeof m);}
  matrix operator * (const matrix &b) {
    matrix ans(this->r, b.c);
    for (int i = 0; i<ans.r; i++){
      for (int j = 0; j<ans.c; j++){
        for (int k = 0; k<b.r; k++){
          ans.m[i][j] += (this->m[i][k] % MOD) * (b.m[k][j] % MOD);
          ans.m[i][j] = ans.m[i][j]%MOD;
        }
      }
    }
    return ans;
  }
};
matrix pow(matrix &b, long long exp){
  matrix ans(b.r, b.c);
  for (int i = 0; i<ans.r; i++) ans.m[i][i] = 1;
  while (exp > 0){
    if (exp & 1){ ans = ans * b;}
    b = b * b;
    exp >>= 1;
  }                                     
  return ans;
}
int main() {
  ll n; cin >> n; matrix ans(4,4); matrix a(4,1);
  //definir a y ans
  a.m[0][0] = 3;
  //..
  ans.m[0][0] = 3;
  //..
  ans= pow(ans, n-2);
  ans = ans * a;
  cout << ans.m[0][0];
  return 0;
}

//factorial o(n)
ll factorial(ll n){
    ll factoriales=1;
    for(int i=1; i<=n; i++){
        factoriales=((factoriales*i)%mod);
    }
    return factoriales;
}

//Combinatoria O(n + log mod)
ll combinaciones(int n, int k) {
    if (k>n) return 0; 
    return (factorial(n)*inv((factorial(k)*factorial(n-k))%mod, mod))%mod;
}

//Permutaciones O(n + log mod)
ll permutaciones(int n, int k) {
    if (k>n) return 0; 
    return (factorial(n) * inv(factorial(n - k), mod)) % mod;
}

//Permutaciones o(n!)
do{
  print(v);
}while(next_permutation(v.begin(), v.end()));

//Meet in the middle 
// o(2**(n))
vl subsets(vl a){
    vl res;
    for (int i=0; i<(1<<a.size()); ++i){  
        ll sum=0;
        for (int j=0; j<a.size(); ++j){
            if (i & (1<<j)) sum+=a[j];
        }
        res.push_back(sum);
    }
    return res;
}
int main(){
    int n; ll x; ll ans =0; cin >> n >> x;
    vl a1(n/2); vl a2(n-n/2);
    for(int i=0; i<n; i++){
        if (i<n/2) cin >> a1[i];
        else cin >> a2[i-n/2];
    }
    vl a3=subsets(a1);
    vl a4=subsets(a2);
    sort(a3.begin(), a3.end()); 
    sort(a4.begin(), a4.end());
    for(ll &sum1 : a3){
        ll sum2 = x - sum1;
        auto low = lower_bound(a4.begin(), a4.end(), sum2);
        auto high = upper_bound(a4.begin(), a4.end(), sum2);
        ans += high - low;
    }
    cout << ans;
}

//Area de un rectangulo, con dos puntos opuestos
ii bla, blb, tra, trb;
cin >> bla.F >> bla.S;
cin >> tra.F >> tra.S;
cin >> blb.F >> blb.S;
cin >> trb.F >> trb.S;
int width=max(tra.F, trb.F)-min(bla.F, blb.F);
int length=max(tra.S, trb.S)-min(bla.S, blb.S);
cout << max(width,length)*max(width,length);

//Area que se intersecta entre dos rectangulos
ll inter_area(vl& s1, vl& s2) {
	return ((min(s1[2], s2[2]) - max(s1[0], s2[0])) *
	        (min(s1[3], s2[3]) - max(s1[1], s2[1])));
}
//True si dos rectangulos se intersectan
bool intersect(vl& s1, vl& s2) {
	if (s1[0] >= s2[2] || s1[2] <= s2[0] || s1[1] >= s2[3] ||
	    s1[3] <= s2[1]) {
		return false;
	}
    return true;
}
//otra forma de calcular el area si estan ordenadas
ll area(vl& s) {
	return (s[3]-s[1]) * (s[2]-s[0]);
}