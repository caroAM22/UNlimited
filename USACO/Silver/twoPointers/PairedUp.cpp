#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define PB push_back
#define all(x) x.begin(), x.end()
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define F first
#define S second
#define sz(x) ((int) x.size())

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n, t; cin >> n;
    ll a, b, sum, mayor;
    vector<pair<ll, int>> vl;
    for(int i=0; i<n;++i){
        cin >> a >> b;
        vl.PB({b, a});
    }
    sort(all(vl));
    int j=sz(vl)-1;
    int i=0;
    mayor=0;
    while(i<j){
        sum=vl[i].F+vl[j].F;
        mayor=max(sum, mayor);
        vl[i].S--; vl[j].S--;
        if(vl[i].S==0) i++;
        if(vl[j].S==0) j--;
    }
    cout << mayor;
    return 0;
}