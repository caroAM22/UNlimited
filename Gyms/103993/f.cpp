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

vi tapa;
vector<vl> memo;
string c;

ll solve(int n, bool f){
    if(n<0) return 0;
    
    if(memo[n][f]!=-1) return memo[n][f];

    int d1=0, d2=0, d3=0, d4=0;
    if(c[n]=='1'){
        d1=tapa[n]+solve(n-1,f);
        if(!f){
            d2=solve(n-1,!f);
        }
    }else if(f){
        d3=tapa[n]+solve(n-1,!f);
    }else{
        d4=solve(n-1,f);
    }
    ll ans=max({d1,d2,d3,d4});
    memo[n][f]=ans;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int n; cin >> n >> c;
    tapa.assign(n, 0);
    memo.assign(n+1,vl(2,-1));
    forx(i,n) cin >> tapa[i];
    cout << solve(n-1,false) << "\n";
    return 0;
}