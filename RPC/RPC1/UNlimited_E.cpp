#include <bits/stdc++.h>
using namespace std;

const char el = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(16) << fixed;

    double x, y; cin >> x >> y;
    double ans, time;
    
    if (x == y) ans = 1.0;
    else {
        time = 100 - x;
        ans = x / (y*time/(100-y));
    }
    cout << ans << el;
    

}