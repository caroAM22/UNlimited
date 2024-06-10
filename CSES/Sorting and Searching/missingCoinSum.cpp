#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define PB push_back
typedef long long ll;
ll INFL = 1e18;

vector<int> v;
set<int> s={0};
int n, t;

bool isTrue(ll x) {
    if(s.count(x)) return true;
    else{
        
    }
}

ll binarySearchLastTrue(ll l, ll r) {
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (isTrue(mid)) {
            l = mid;  
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int num;
    cin >> n >> t;
    v.PB(0);
    for(int i=0; i<n; ++i){
        cin >> num;
        v.PB(num);
        s.insert(num);
    }
    sort(all(v));
    cout << binarySearchLastTrue(0, 1e18);
    return 0;
}

