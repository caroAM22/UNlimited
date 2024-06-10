#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a; cin >> n;
    int cont=0;
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> a;
        if(s.count(a)==0){
            cont++;
            s.insert(a);
        }
    }
    cout << cont;
    return 0;
}