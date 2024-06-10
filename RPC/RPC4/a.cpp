#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout << setprecision(20) << fixed;
    
    int m, n; cin >> m >> n;
    if (m*2 >= n) cout << "E" << "\n";
    else cout << "H" << "\n";
    
    return 0;
}