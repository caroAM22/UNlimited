#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

using namespace std;

int main() {
    ll n,a;
    cin >> n;
    vi v(n, -1);

    v[0] = 0;
    ll cont = 0, suma = 0;
    for (int i = 0; i < n; i++){
        cin >> a;
        suma = ((suma+a)%n+n)%n;
        cont += ++v[suma];
    }
    cout << cont;
    return 0;
}