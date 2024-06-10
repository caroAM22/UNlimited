#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INFL = 1e18;
int n, k;

vector<int> v;

int f(int x) {
    vector<int> v1;
    v1.clear();
    for(int i=0; i<n; ++i){
        v1.push_back(abs(v[i]-x));
    }
    sort(v1.begin(), v1.end());
    return v1[k];
}

int binarySearch(int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (f(mid) <= f(mid+1)) {
            r = mid; 
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, num;
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n >> k;
        v.clear();
        for(int j=0; j<n; ++j){
            cin >> num;
            v.push_back(num);
        }
        cout << binarySearch(0, 1e9) << "\n";
    }
    return 0;
}