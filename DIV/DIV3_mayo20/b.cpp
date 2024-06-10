#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    //cout<<setprecision(20)<<fixed;
    int t, n, ta; cin >> t;
    forx(i,t){
        string s, r;
        set<char> sc;
        map<char, char> m;
        cin >> n;
        cin >> s;
        for(auto &x: s){
            sc.insert(x);
        }
        for(auto &x: sc){
            r+=x;
        }
        if(sz(r)%2==0) ta=(sz(r)/2);
        else ta=(sz(r)/2)+1;
        forx(j,ta){
            m.insert({r[j],r[sz(r)-j-1]});
            m.insert({r[sz(r)-j-1],r[j]});
        }
        for(auto &x: s){
            cout << m[x];
        }
        cout << "\n";
    }
    return 0;
}