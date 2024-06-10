#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using ii = pair<int, int>;
 
void solve() {
 
    int n, k;
    cin >> n >> k;
 
    vi a(n);
    for (int &ai : a) cin >> ai;
 
    int low = 0;
    int high = 1e9;
 
    int ans = 0;
 
    auto f = [&] (int x) -> int {
 
        for (int i = 0; i + k < n; i++) {
            int y = (a[i] + a[i + k]) / 2;
            
            if (abs(a[i] - y) <= x && abs(a[i + k] - y) <= x) {
                return y;
            }
            else if ((abs(a[i] - y - 1) <= x && abs(a[i + k] - y - 1) <= x)) {
                return y + 1;
            }
        }
 
        return -1;
 
    };
 
    while (low <= high) {
 
        int mid = (low + high) / 2;
 
        if (f(mid) != -1) {
            ans = f(mid); 
            high = mid - 1;
        } else {
            low = mid + 1;
        }
 
    }
 
    cout << ans << endl;
 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
 
    while (t--) {
        solve();
    }
 
    return 0;
}
