#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INFL = 1e18;

vector<int> machines;
int n, t;

bool isTrue(ll x) {
    ll s=0;
    ll p;
    for(int i=0; i< n; ++i){
        p = x/machines[i];
        if(s+p>=t) return true;
        else s+=p;
    }
    return s>=t;
}

ll binarySearchFirstTrue(ll l, ll r) {
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (isTrue(mid)) {
            r = mid;  
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int num;
    cin >> n >> t;
    for(int i=0; i<n; ++i){
        cin >> num;
        machines.push_back(num);
    }
    cout << binarySearchFirstTrue(0, 1e9);
    return 0;
}

