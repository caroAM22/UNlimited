#include <bits/stdc++.h>
using namespace std;

vector<long long> primos;
void criba(long long n){
  vector<bool> is_prime(n+1, true);
  for(long long i=2;i<=n;++i){
    if(is_prime[i]){
      for(long long j=i*i;j<=n;j+=i)is_prime[j]=false;
      primos.push_back(i);
    }
  }
}

int main() {
    criba(1000);
    cout << primos.size();
    return 0;
}