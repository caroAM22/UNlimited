#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define PB push_back
typedef long long ll;
ll INFL = 1e18;

vector<int> arr;
int n, k;

bool isTrue(ll x) {
    ll cont=0;
    for (int i = n / 2; i < n; ++i) {
        cont += max((ll)0, x - arr[i]);
        if(cont>k) break;
    }
    if(cont<=k) return true;
    return false;
}

int binarySearchLastTrue(int l, int r) {
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
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
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> num;
        arr.PB(num);
    }
    sort(all(arr));
    cout << binarySearchLastTrue(arr[n/2], 1e18);
    return 0;
}