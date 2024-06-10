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


int main(){
    ll n, a; cin >> n;
    vl v; 
    for(int i=0; i<n; ++i){
        cin >> a;
        v.PB(a);
    }
    sort(all(v));
    ll prom=v[n/2];
    ll cont=0;
    for(int i=0; i<n; ++i){
        cont=cont+(abs(prom-v[i]));
    }
    cout << cont;
    return 0;
}