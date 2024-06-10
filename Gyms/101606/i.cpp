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
    cout<<setprecision(20)<<fixed;
    int n,t,a; cin >> n;
    vi v(n);
    forx(i,n) cin >> v[i];
    cin >> t;
    int mini=INT_MAX;
    forx(i,n){
        if(t%v[i]<mini){
            mini=t%v[i];
            a=v[i];
        }
    }
    cout << a;
    return 0;
}