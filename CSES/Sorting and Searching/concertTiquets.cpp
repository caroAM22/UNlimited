#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a,res; cin >> n >> m;
    multiset<int> tiquets;
    vector<int> personas(m);
    for(int i=0; i<n; i++){
        cin >> a;
        tiquets.insert(-a);
    }
    for(int i=0; i<m; i++){
        cin >> personas[i];
    }
    for(int i=0; i<m; i++){
        auto it = tiquets.lower_bound(-personas[i]);
        if (it == tiquets.end()){
            cout << -1 << "\n";
        }else{
            cout << -(*it) << "\n";
            tiquets.erase(it);
        }
    }
    return 0;
}