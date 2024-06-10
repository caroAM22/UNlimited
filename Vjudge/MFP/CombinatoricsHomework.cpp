#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define PB push_back
typedef long long ll;
typedef vector<ll> vl;

int main() {
    int t;
    ll a, m; 
    cin >> t;
    for(int i=0; i<t; ++i){
        vl v;
        for(int i=0; i<3; ++i){
            cin >> a;
            v.PB(a);
        }
        cin >> m;
        sort(all(v));
        a=v[0];
        for(int i=0; i<3; ++i){
           v[i]-=a;
        }
        if(v[1]>=v[2]-1 && (v[1]+v[2])>=m) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}