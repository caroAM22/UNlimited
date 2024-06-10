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
    int n; cin >> n;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        set<char> c;
        for(auto &ca: s){
            c.insert(ca);
        }
        if(sz(c)==1) cout << "NO\n";
        else{
            cout << "YES\n";
            string ne=s.substr(sz(s)/2,sz(s))+ s.substr(0, sz(s)/2);
            if(ne==s and sz(s)>2){
                ne=s.substr(sz(s)/2+1,sz(s))+ s.substr(0, sz(s)/2+1);
            }
            cout << ne << "\n";
        }
    }
    return 0;
}