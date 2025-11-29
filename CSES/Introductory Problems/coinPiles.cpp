#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        // Condición 1: la suma total debe ser múltiplo de 3
        if ((a + b) % 3 != 0) {
            cout << "NO\n";
            continue;
        }

        // Condición 2: ninguna pila puede ser más del doble de la otra
        long long mn = min(a, b);
        long long mx = max(a, b);

        if (mn * 2 < mx) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
