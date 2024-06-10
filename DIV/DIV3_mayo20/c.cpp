#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef vector<int> vi;
typedef tuple<int, int, int> tiii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        vi v(n);
        forx(i, n) cin >> v[i];

        map<tiii, int> m;
        forx(i, n-2) {
            m[make_tuple(v[i], v[i+1], v[i+2])]++;
        }

        long long cont = 0;

        for (auto it1 = m.begin(); it1 != m.end(); ++it1) {
            for (auto it2 = next(it1); it2 != m.end(); ++it2) {
                int diff = 0;
                if (get<0>(it1->first) != get<0>(it2->first)) diff++;
                if (get<1>(it1->first) != get<1>(it2->first)) diff++;
                if (get<2>(it1->first) != get<2>(it2->first)) diff++;
                
                if (diff == 1) {
                    cont += it1->second * it2->second;
                }
            }
        }

        cout << cont << "\n";
    }

    return 0;
}
