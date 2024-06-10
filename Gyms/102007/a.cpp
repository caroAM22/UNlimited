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
    int n, x; cin >> n >> x;
    vi v(n);
    forx(i,n) cin >> v[i];
    if(n==1) cout << 1;
    else{
        sort(all(v));
        forx(i,n-1){
            if(v[i]+v[i+1]>x){
                cout << i+1;
                break;
            }else if(i==n-2){
                cout << n;
                break;
            }
        }
    }
    return 0;
}