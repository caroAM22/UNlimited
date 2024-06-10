#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define PB push_back
typedef long long ll;
typedef vector<int> vi;

int main() {
    int t, a, n, m; 
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n;
        vi v;
        for(int j=0; j<n; ++j){
            cin >> a;
            v.PB(a);
        }
        sort(all(v));
        if(n%2==0) m=(n/2)-1;
        else m=n/2;
        auto low = lower_bound(v.begin()+m, v.end(), v[m]);
        auto high = upper_bound(v.begin()+m, v.end(), v[m]);
        cout << high-low << "\n";
    }
    return 0;
}