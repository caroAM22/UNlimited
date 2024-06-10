#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, k, num;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> num;
        arr[i] = num;
    }
    sort(arr, arr+n);
    int a, b;
    for (int i=0; i<k; ++i){
        cin >> a >> b;
        cout << upper_bound(arr, arr+n, b) - lower_bound(arr, arr+n, a) << "\n";
    }
    return 0;
}