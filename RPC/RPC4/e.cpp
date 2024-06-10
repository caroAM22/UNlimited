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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
const int MOD = 1e9+7;

int main(){
    int n, k; cin >> n >> k;
    vl vec;
    ll sum=0; 
    ll prefix=0;
    ll a;
    for(int i=0; i<n; ++i){
        cin >> a;
        vec.PB(a);
        if(i<k) sum=sum+a;
        if(i<k) prefix=prefix+(a*(i+1));
    }
    ll p=1;
    set<ii> s={{prefix, p}};
    p++;
    for(int i=k; i<n; ++i){
        prefix=prefix-sum+(vec[i]*k);
        sum=sum-vec[i-k]+vec[i];
        s.insert({prefix, p});
        p++;
    }
    for(auto &x: s){
        cout << x.S << " " << x.F << "\n";
    }
    return 0;
}