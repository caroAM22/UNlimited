#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INFL = 1e18;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    ll num;
    cin >> n >> m;
    priority_queue<ll> t;
    priority_queue<ll> b;
    for(int i=0; i<n; ++i){
        cin >> num;
        t.push(num);
    }
    for(int i=0; i<m; ++i){
        cin >> num;
        b.push(num);    
    }
    t.pop();
    ll r=b.top() * t.top();
    cout << r;
    return 0;
} 
