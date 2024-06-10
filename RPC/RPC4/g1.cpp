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
    int n, a, k; cin >> n>> a;
    string no; ll s, s1;
    map<pair<ll, string>, string> m;
    map<string,ll> m1;
    for(int i=0; i<n; ++i){
        cin >> no >> s;
        m.insert({{-s,no},no});
        m1.insert({no,s});
    }
    for(int i=0; i<a;++i){
        cin >> k;
        if(k==2){
            for(auto &x: m){
                cout << x.S << " " << -x.F.F << "\n";
                m.erase(x.F);
                m1.erase(x.S);
                break;
            }
        }else{
            cin >> no >> s;
            s1=m1[no];
            m.erase({-s1,no});
            s1=s1+s;
            m.insert({{-s1,no},no});
            m1[no]+=s;
        }
    }
    return 0;
}