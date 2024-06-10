#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vl;
#define forx(i,n) for(int i=0; i<(int)n; ++i)

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, x;
    ll v, res, f;
    cin >> n;
    vl a(n);
    for (int &ai : a) cin >> ai;
    cin >> x >> f;
    ll c=0;
    forx(i,n){
        v = static_cast<ll>(a[i]/(x+f));
        if(a[i]%(x+f)>x){
            v++;
        }
        c+=v;
    }
    ll resul = c*f;
    cout << resul;
    return 0;
}

