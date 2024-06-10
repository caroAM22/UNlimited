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
    int n, k; cin >> n >> k;
    vi v(n);
    forx(i,n) cin >> v[i];
    int j=0; int i=0;
    set<int> s; multiset<int> s1;
    ll cont=0;
    while(j<n){
        if(s.count(v[j]) && sz(s)<=k){
            cont+=1+sz(s1);
            s.insert(v[j]);
            s1.insert(v[j]);
        }else{
            while(sz(s)>=k){
                s1.erase(s1.find(v[i]));
                if(s1.count(v[i])==0){
                    s.erase(v[i]);
                }
                i++;
            }
            cont+=1+sz(s1);
            s.insert(v[j]);
            s1.insert(v[j]);
        }
        j++;
    }
    cout << cont;
    return 0;
}
