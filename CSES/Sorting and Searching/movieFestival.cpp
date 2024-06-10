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
typedef pair<int, int> ii;
typedef vector<ii> vi;


int main(){
    int n, a, b; cin >> n;
    vi v; 
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        v.PB({b,a});
    }
    sort(all(v));
    int cont=1;
    ii ant=v[0];
    for(int i=1; i<n; ++i){
        if(v[i].S>=ant.F){
            cont++;
            ant=v[i];
        }
    }
    cout << cont;
    return 0;
}