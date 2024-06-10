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
typedef vector<tuple<ll, ll, double, double>> vt; 
typedef vector<ii> vii;
const int MOD = 1e9+7;

vl ai;

int binary(ll x){
    int l=0; int r=sz(ai);
    while(l<=r){
        int m=l+(r-l)/2;
        if(ai[m]==x) return m;
        else if(ai[m]>x) r=m-1;
        else l=m+1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    ll t, n, k, b, q; cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> k >> q;
        ai.resize(k+1); vl bi(k+1); 
        ai[0]=0; bi[0]=0;
        for(int j=1; j<k+1; j++) cin >> ai[j];
        for(int j=1; j<k+1; ++j) cin >> bi[j];
        for(int j=0; j<q; ++j){
            cin >> b; 
            int p=binary(b);
            if(ai[p]==b) cout << bi[p] << " ";
            else{
                ll vel=((bi[p]-bi[p-1])/((ll)ai[p]-ai[p-1]))*(b-ai[p-1]);
                ll res=bi[p-1]+vel;
                cout << res << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}