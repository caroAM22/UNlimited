#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n; ll x, a; cin >> n >> x;
    map<ll, ll> res={{0,1}};
    int cont=0;
    ll prefix=0;
    for(int i=0; i<n; i++){
        cin >> a;
        prefix+=a;
        res[prefix]++;
        if(res.count(prefix-x)) cont++;
    }
    cout << cont;
    return 0;
}