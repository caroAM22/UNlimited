#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<n; ++i)
using ll=long long int;
using vl=vector<ll>;
using vll=vector<vl>;
#define pb push_back

bool isValid(ll x, const multiset<ll>& s, int n, ll c, ll d) {
    vll v(n, vl(n, 0)); 
    ll num;
    multiset<ll> s_copy = s;
    forx(i,n) {
        forx (j,n) {
            if (i == 0 && j == 0){
                v[i][j] = x;
            }else{
                if(j!=0){
                    num = v[i][j-1] + d;
                }
                if(i!=0 and j!=0){
                    if(num!=v[i-1][j]+c){
                        return false;
                    }
                }
                if(j==0){
                    num = v[i-1][j] + c;
                }
                v[i][j] = num;
            }
            if (s_copy.count(v[i][j])==0) 
                return false;
            else{
                s_copy.erase(s_copy.find(v[i][j]));
            }
        }
    }
    return true; 
}

void solve(){
    int n;
    ll c, d, x;
    cin >> n >> c >> d;
    multiset<ll> s;
    for (int i = 0; i < n*n; ++i) {
        cin >> x;
        s.insert(x);
    }
    ll num = *s.begin();
    if (isValid(num, s, n, c, d)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
