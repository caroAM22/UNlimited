#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    ll n; cin >> n;
    if(n==1) cout << 1 << "\n";
    else{
        int i=0;
        ll k=2;
        while(k<n){
            k *= 2;
            i++;
        }
        cout << i+2 << "\n";
    }
    return 0;
}