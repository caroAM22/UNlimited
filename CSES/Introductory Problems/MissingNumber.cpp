#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a; cin >> n;
    set<int> s;
    for(int i=1; i<n+1; i++) s.insert(i);
    for(int i=0; i<n; i++){
        cin >> a;
        s.erase(a);
    }
    for(int u: s){
        cout << u;
    }
    return 0;
}