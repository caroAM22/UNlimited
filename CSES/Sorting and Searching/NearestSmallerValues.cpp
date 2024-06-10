#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int main(){
    int n, a; cin >> n;
    stack<pair<int, int>> p;
    for(int i=1; i<n+1; ++i){
        cin >> a;
        if(p.empty()){
           cout << 0 << " ";
        } 
        else{
            auto s=p.top();
            while(s.F>=a){
                p.pop();
                if(p.empty()) break;
                s=p.top();
            }
            if(p.empty()){
                cout << 0 << " ";
            } else cout << s.S << " ";
        }
        p.push({a, i});
    }
    return 0;
}