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
 
int n;
vector<char> l;
vi memo;
 
int solve(int x){
    forx(i,6) memo[i+1]++;
    for(int i=2; i<=x; i++){
        for(int j=i-1; j>=max(1,i-6); j--){
           memo[i]=(memo[j]%MOD+memo[i]%MOD)%MOD;
        }
    }
    return memo[x];
}
 
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    memo.assign(n+1,0);
    cout << solve(n);
    return 0;
}