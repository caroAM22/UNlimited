#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<"\n";
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef priority_queue<int> pi;
typedef map<int,int> mi;
const int MOD = 1e9+7;
const string ABC = "abcdefghijklmnopqrstuvwxyz";

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n; cin >> n;
    string s;
    mi def;
    forx(i,n){
        mi m;
        mi m2;
        forx(i,2){
            cin >> s;
            for(char c: s){
                if(i%2==0)m[c]++;
                else m2[c]++;
            }
        }
        for (const auto &c : ABC) {
            def[c]+=max(m[c],m2[c]);
        }
    }
    for (const auto &c : ABC) {
        cout << def[c] << "\n";
    }
    return 0;
}