#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INFL = 1e18;
vector<int> arr;

void sieve(int n) {
  vector<bool> is_prime(n + 1, 1);

  is_prime[0] = is_prime[1] = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        is_prime[j] = 0;
      }
    }
  }
}

int numDiv(long long N) {
  int ans = 1; 
  for (int i = 0; i < (int)p.size() && (p[i] * p[i] <= N); ++i) {
    int power = 0; 
    while (N % p[i] == 0) { N /= p[i]; ++power;}
    ans *= power + 1;
  }
  if (N != 1) return 2 * ans;
  else return ans;
}

long long sumDiv(long long N) {
  long long ans = 1;
  for (int i = 0; i < (int)p.size() && (p[i] * p[i] <= N); ++i) {
    long long multiplier = p[i]; long long total = 1;
    while (N % p[i] == 0) {
      N /= p[i];
      total += multiplier;
      multiplier *= p[i];
    }
    ans *= total;
  }
  if (N != 1) ans *= (N + 1); 
  return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int num, n, t;
    cin >> n >> t;
    for(int i=0; i<n; ++i){
        cin >> num;
        arr.push_back(num);
    }
    return 0;
}