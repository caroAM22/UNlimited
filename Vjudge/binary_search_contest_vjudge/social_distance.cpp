#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INFL = 1e18;

vector<int> arr;
int n, k;

bool isTrue(ll x) {
    ll s=0;
    for(int i=0; i< n; ++i){
        s+=x/arr[i];
    }
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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int num;
    cin >> n >> k;
    for(int i=0; i<k; ++i){
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    cout << binarySearchFirstTrue(0, 1e18);
    return 0;
}