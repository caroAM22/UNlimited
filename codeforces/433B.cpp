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

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, m, a,b,t; cin >> n;
    vl vo(n+1); vo[0]=0;
    vl vu(n+1); vu[0]=0;
    vl v(n);
    forx(i,n) cin >> v[i];
    vl v1=v;
    sort(all(v));
    for(int i=1; i<=n; ++i){
        vo[i]=vo[i-1]+v[i-1];
        vu[i]=vu[i-1]+v1[i-1];
    }
    cin >> m;
    forx(i,m){
        cin >> t >> a >> b;
        if(t==1){
            cout << vu[b]-vu[a-1];
        }else{
            cout << vo[b]-vo[a-1];
        }
        cout << "\n";
    }
    return 0;
}