#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define forx(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) x.begin(), x.end()
typedef long long int ll;

vector<int> v;
int n, c, m;

bool isTrue(ll x) {
    int cow = v[0];
    int b = 1;
    int nc = 0;
    for (int t : v) {
        nc++;
        if (t - cow > x || nc > c) {
            b++;
            nc = 1;
            if (b > m) return false;
            cow = t;
        }
    }
    return true;
}

ll binarySearchft(ll l, ll r) {
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
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    ll num;
    cin >> n >> m >> c;
    forx(i,n){
        cin >> num;
        v.PB(num);
    }
    sort(all(v));
    cout << binarySearchft(0,1e18);
    return 0;
}