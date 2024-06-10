#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m,a, k, res; cin >> n >> m >> k;
    multiset<int> personas;
    multiset<int> apartamentos;
    for(int i=0; i<n; i++){
        cin >> a;
        personas.insert(a);
    }
    for(int i=0; i<m; i++){
        cin >> a;
        apartamentos.insert(a);
    }
    int cont=0;
    for(auto u: personas){
        res=*apartamentos.lower_bound(u-k);
        if(res>=u-k && res<=k+u){
            cont++;
            apartamentos.erase(apartamentos.find(res));
        }
    }
    cout << cont;
    return 0;
}