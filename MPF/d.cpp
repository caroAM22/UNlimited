#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
priority_queue<int> pq;
int p;

bool isTrue(ll x) {
    ll sum=0;
    priority_queue<int> pq1=pq;
    while(!pq1.empty() && -pq1.top() <= x){
        sum+=(x/(-pq1.top()));
        pq1.pop();
        if (sum >= p) return true;
    }
    return false;
}

ll binarySearchFirstTrue(ll l, ll r) {
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (isTrue(mid)) {
            r = mid;  
        } else {
            l = mid + 1;
        }
    }
    return l;
}
    

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, a;
    cin >> n >> p;
    for (int i=0; i<n; ++i){
        cin >> a;
        pq.push(-a);
    }
    cout << binarySearchFirstTrue(0, 1e18);
    return 0;
}