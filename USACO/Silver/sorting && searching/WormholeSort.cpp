#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef tuple<int, int, int> t;
typedef vector<int> vi;
typedef vector<t> vt;
#define PB push_back

int main(){
    // freopen("wormsort.in", "r", stdin);
    // freopen("wormsort.out", "w", stdout);
    int n, m, a, b, p; cin >> n>> m;
    vi vec(n); 
    vt v;
    bool f=true;
    for(int i=0; i<n; ++i){
        cin >> vec[i];
        if(vec[i]!=i+1) f=false;
    }
    for(int i=0; i<m; ++i){
        cin >> a >> b >> p;
        v.PB({-p, a, b});
    }
    sort(all(v));
    int i=0;
    bool f1=false;
    int mini=INT_MAX;
    while(!f && i<m){
        a=get<1>(v[i]);
        b=get<2>(v[i]);
        if(vec[a-1]!=a || vec[b-1]!=b){
            auto it1 = next(vec.begin(), a-1);
            auto it2 = next(vec.begin(), b-1);
            swap(*it1, *it2);
            if(f1){
                i--; 
                f1=false;
            }
            else{
                i++; 
                f1=true;
            }
            mini=min(mini,-get<0>(v[i]));
        }else{
            i++;
        }
    }
    if(f) cout << -1;
    else cout << mini;
    return 0;
}