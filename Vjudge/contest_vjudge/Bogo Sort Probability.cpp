#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<n; ++i)
using ll=long long int;
using vl=vector<ll>;
ll mod = 1e9+7;

vl factoriales;

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

void factorial(vl& factoriales, ll n){
    factoriales.push_back(1);
    for(int i=1; i<=n; i++){
        factoriales.push_back((factoriales[i-1]*i)%mod);
    }
    return;
}

ll product_of_factorials(map<ll, ll>& repetitions) {
    ll result = 1;
    for(auto &x: repetitions){
        result = (result*factoriales[x.second])%mod;
    }
    return result;
}

void print(ll& fact, ll& f, map<ll, ll>& nums, ll& res){
    fact=(f*(inv(res,mod)))%mod;
    ll prob=(1*(inv(fact,mod)))%mod;
    cout << prob << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n, k, a, b, m, f, fact, x, res;
    cin >> n >> k;
    map<ll, ll> nums;
    vl vec(n);
    factorial(factoriales, n);
    forx(i,n){
        cin >> x;
        vec[i]=x;
        nums[x]++;
    }
    f=factoriales[n];
    res=product_of_factorials(nums);
    print(fact, f, nums, res);

    forx(i, k){
        cin >> a >> b;
        res=(res*inv(nums[vec[a-1]],mod))%mod;
        nums[vec[a-1]]--;
        if(nums[vec[a-1]]==0){
            nums.erase(vec[a-1]);
        }
        nums[b]++;
        res=(res*nums[b])%mod;
        vec[a-1]=b;
        print(fact, f, nums,res);
    }
    return 0;
}
