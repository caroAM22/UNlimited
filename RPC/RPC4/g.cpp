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
    string no, menor; ll s,s1, mayor;
    multimap<ll, string> m;
    map<string,ll> m1;
    for(int i=0; i<n; ++i){
        cin >> no >> s;
        m.insert({-s,no});
        m1.insert({no,s});
    }
    for(int i=0; i<a;++i){
        cin >> k;
        if(k==2){
            mayor = m.begin()->F;
            auto range = m.equal_range(mayor);
            multimap<ll, string>::iterator it_to_erase;
            for(auto j = range.F; j != range.S; ++j) {
                if(j==range.F){
                    menor=j->S;
                    it_to_erase = j;
                }
                if(j->S<menor){
                    menor=j->S;
                    it_to_erase = j;
                }
            }
            cout << it_to_erase->S << " " << -mayor << "\n";
            m1.erase(it_to_erase->S);
            m.erase(it_to_erase); 
        }else{
            cin >> no >> s;
            s1=m1[no];
            m1[no]+=s;
            auto range = m.equal_range(-s1);
            for(auto j = range.first; j != range.second; ) {
                if(j->second == no) {
                    ll new_key = j->first - s;
                    m.insert({new_key, no});
                    j = m.erase(j); 
                    break;
                } else {
                    ++j;
                }
            }
        }
    }
    return 0;
}