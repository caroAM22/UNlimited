#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pair<string, int>> vpsi;
typedef set<int> si;
typedef bool b;

const char el = '\n';
const int mod = 1e9 + 7;
vl primes;
si lenghts;

void sieve(int n) {
    vb is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;

    for (long long i = 2; i*i <= n; ++i) {
        if (is_prime[i]) {
            for (long long j = i*i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int i = 2; i < n; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

void solve(ll c, ll m, int max) {
    sieve(max);
    for (auto prime: primes) {
        if (c % prime == 0 && lenghts.count(prime)) {
            auto other = c / prime;
            if (lenghts.count(other)) {
                cout << prime << " " << other << el;
                return;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout << setprecision(20) << fixed;

    ll c; cin >> c;
    ll m; cin >> m;
    int max = 0;
    int aux;
    
    FOR(i, m) {
        cin >> aux;
        lenghts.insert(aux);
        if (aux > max) max = aux;
    }
    solve(c, m, max);

    return 0;
}