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

vi monedas;
vi memo;
int k; 
int t; 

ll solve(int n){
    if(n>t) return 0;

    if (memo[n] != -1) return memo[n];

    ll d1=monedas[n-1]+solve(n*2);
    ll d2=monedas[n-1]+solve(n*2+1);
    ll ans=max(d1,d2);
    memo[n]=ans;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> t;
    k=pow(2,t-1);
    t=pow(2,t)-1;
    monedas.assign(t,0);
    memo.assign(t+1,-1);
    forx(i,t) cin >> monedas[i];
    cout << solve(1);
    return 0;
}