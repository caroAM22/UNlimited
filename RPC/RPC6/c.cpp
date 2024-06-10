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
typedef vector<pair<string, int>> vpsi;
typedef set<int> si;
typedef bool b;

const char el = '\n';
const int mod = 1e9 + 7;
vl primes;

void sieve(int n) {
    vector<bool> is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;

    for (long long i = 2; i*i <= n; ++i) {
        if (is_prime[i]) {
            for (long long j = i*i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int i = 2; i < n; ++i) {
        if (is_prime[i]) primes.pb(i);
    }
}

int solve() {
    ll N, T; cin >> N >> T;

    if (T == 1) return N;
    T--;

    int ans = 1; 
    if (N >= T) {
        for (int i = 0; i < (int)primes.size() && 
        (primes[i] * primes[i] <= T) && (primes[i] <= N); ++i) {
            int power = 0; 
            while (T % primes[i] == 0) {
                T /= primes[i]; 
                ++power;
            }
            ans *= power + 1;
        }
        if (T != 1) return 2 * ans;
        else return ans;
    } else {
        for (int i = 2; i <= N; ++i) {
            if (T % i == 0) ans++;
        }
        return ans;
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout << setprecision(20) << fixed;
    
    sieve(1e5);
    int t; cin >> t;
    while (t--) {
        cout << solve() << el;
    }

    return 0;
}