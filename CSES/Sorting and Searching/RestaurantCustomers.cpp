#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define PB push_back
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define F first
#define S second
#define all(x) x.begin(), x.end()

int main(){
    int n, a, b; cin >> n;
    set<int> s; 
    map<int, int> m;
    vector<pair<int, int>> vi;
    for(int i=0;i<n; ++i){
        cin >> a >> b;
        s.insert(a);
        s.insert(b);
        vi.PB({a,b});
    }
    int i=0;
    for(auto &x: s){
        m.insert({x,i});
        i++;
    }
    sort(all(vi));
    vector<int> vec(i, 0);
    for(auto &x: vi){
        vec[m[x.F]]++; 
        vec[m[x.S]]--;
    }
    int mayor=0;
    int prefix=0;
    for(int j=0; j<i; ++j){
        prefix=prefix+vec[j];
        mayor=max(prefix, mayor);
    }
    cout << mayor;
    return 0;
}