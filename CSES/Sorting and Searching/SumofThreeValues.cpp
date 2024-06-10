#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
#define PB push_back
#define all(x) x.begin(), x.end()
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"

int main(){
    int n; cin >> n; ll x, a; cin >> x;
    map<ll, vi> m;
    vector<ll> vec;
    for(int i=0; i<n; ++i){
        cin >> a;
        vec.PB(a);
        if(m.count(a)){
            m[a].PB(i);
        }else {
            vi v={i};
            m.insert({a,v});
        }
    } 
    bool b=false;
    for(int i=0; i<n-1; ++i){
        ll sum=vec[i];
        for(int j=i+1; j<n; ++j){
            sum+=vec[j];
            if(m.count(x-sum)){
                for(auto &u: m[x-sum]){
                    if(b) break;
                    if(u!=j && u!=i){
                        cout << i+1 << " " << j+1 << " " << u+1;
                        b=true;
                    }
                }
            }
            sum=vec[i];
        }
        if(b) break;
    }
    if(!b) cout << "IMPOSSIBLE";
    return 0;
}