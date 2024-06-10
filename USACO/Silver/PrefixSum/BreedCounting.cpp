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
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q, a, b; cin>> n>>q;
    vector<int> u(n+1,0);
    vector<int> d(n+1,0);
    vector<int> t(n+1,0);
    for(int i=1; i<n+1; ++i){
        cin >> a;
        u[i]=u[i-1];
        d[i]=d[i-1];
        t[i]=t[i-1];
        if(a==1){
            u[i]++;
        }else if(a==2){
            d[i]++;
        }else{
            t[i]++;
        }
    }
    for(int i=0; i<q; ++i){
        cin >> a >> b;
        cout << u[b]-u[a-1] << " " << d[b]-d[a-1] << " " <<  t[b]-t[a-1] <<"\n";
    }
    return 0;
}