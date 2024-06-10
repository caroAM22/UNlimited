#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<"\n";
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
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int a, b; 
    vi c(3);
    vi l(3);
    forx(i,3){
        cin >> c[i] >> l[i];
    }
    forx(i,100){
        b=(i+1)%3; a=i%3;
        if (l[b]+l[a]<=c[b]){
            l[b]+=l[a];
            l[a]=0;
        }
        else{
            l[a]=l[a]-(c[b]-l[b]);
            l[b]=c[b];
        }
    }
    print(l);
    return 0;
}