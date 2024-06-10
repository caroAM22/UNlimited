#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using vl = vector<ll>;
using pll = priority_queue<ll>;
#define forx(i,n) for(int i=0; i<(int)n; ++i)

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n, a;
    cin >> n;
    ll health=0;
    pll pq;
    forx(i, n){
        cin >> a;
        health+=a;
        pq.push(-a);
        while(!pq.empty()){
            if(health>=0) break;
            health-=(-pq.top());
            pq.pop();
        }
    }
    cout << pq.size() << "\n";
    return 0;
}