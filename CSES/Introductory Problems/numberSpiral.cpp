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
    int t, a, b; cin >> t;
    ll m, dig;
    forx(i,t){
        cin >> a >> b;
        m=max(a,b);
        dig=(m*m)-(m-1);
        if(a==b) cout << dig;
        else if(m%2==0){
            if(a<m) cout << dig-(m-a);
            else if(b<m) cout << dig+(m-b);
        }else{
            if(a<m) cout << dig+(m-a);
            else if(b<m) cout << dig-(m-b);
        }
        cout << "\n";
    }
    return 0;
}