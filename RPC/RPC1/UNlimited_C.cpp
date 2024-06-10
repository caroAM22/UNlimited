#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string, int> vsi;
typedef vector<string> vs;
typedef vector<int> vi;

const char el = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;

    int n; cin >> n;
    vs characters(n);

    for (auto &i: characters) cin >> i;
    for (auto i: characters) cout << i;
    
}