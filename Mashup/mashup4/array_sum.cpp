#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<int> vi;
typedef set<int> s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, k;
    cin >> t;
    forx(i,t){
        cin >> n >> k;
        vi a(n);
        s mset;
        forx(j,n){
            cin >> a[j];
            mset.insert(a[j]);
        }
        int setSize = static_cast<int>(mset.size());
        if (setSize > k){
            cout << -1 << "\n";
        }else{
            cout << n*k << "\n";
            forx(j,n){
                forx(l,k){
                    cout << a[j] << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}