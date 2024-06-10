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

ll suma;
vl a;
int n; 

pair<ll,ll> subsets(){
    ll res=suma;
    ll res2=suma%360;
    for (int i=0; i<(1<<a.size()); ++i){  
        ll s=0;
        for (int j=0; j<a.size(); ++j){
            if (i & (1<<j)){
                s+=a[j];
            }
        }
        ll dif=abs(s-(suma-s));
        ll mod=abs(s-(suma-s))%360;
        res2=min(res2,mod);
        res=min(dif,res);
    }
    return {res,res2};
}


int main(){
    cin >> n;
    a.resize(n);
    suma=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        suma+=a[i];
    }
    pair<ll,ll> res=subsets();
    // cout << res.F << " " << res.S << "\n";
    if(res.F==0 || res.S==0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}