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
 
const int nmax = 100;
const ll MOD = 1e9+7;

struct matrix{
  int r, c;
  long long m[nmax][nmax];
  matrix (int r, int c): r(r), c(c) {memset(m, 0, sizeof m);}
  matrix operator * (const matrix &b) {
    matrix ans(this->r, b.c);
    for (int i = 0; i<ans.r; i++){
      for (int j = 0; j<ans.c; j++){
        for (int k = 0; k<b.r; k++){
          ans.m[i][j] += (this->m[i][k] % MOD) * (b.m[k][j] % MOD);
          ans.m[i][j] = ans.m[i][j]%MOD;
        }
      }
    }
    return ans;
  }
};
matrix pow(matrix &b, long long exp){
  matrix ans(b.r, b.c);
  for (int i = 0; i<ans.r; i++) ans.m[i][i] = 1;
  while (exp > 0){
    if (exp & 1){ ans = ans * b;}
    b = b * b;
    exp >>= 1;
  }                                     
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  ll n; cin >> n;
  matrix ans(4,4);
  matrix a(4,1);
  a.m[0][0] = 3;
    a.m[1][0] = 2;
    a.m[2][0] = 1;
    a.m[3][0] = 1;

  ans.m[0][0] = 3;
  ans.m[0][1] = 2;
  ans.m[0][2] = 1;
  ans.m[0][3]= 3;
    ans.m[1][0] = 1;
    ans.m[1][1] = 0;
    ans.m[1][2] = 0;
    ans.m[1][3] = 0;
    ans.m[2][0] = 0;
    ans.m[2][1] = 1;
    ans.m[2][2] = 0;
    ans.m[2][3] = 0;
    ans.m[3][0] = 0;
    ans.m[3][1] = 0;
    ans.m[3][2] = 0;
    ans.m[3][3] = 1;
  ans= pow(ans, n-2);
  ans = ans * a;
  cout << ans.m[0][0];
  return 0;
}