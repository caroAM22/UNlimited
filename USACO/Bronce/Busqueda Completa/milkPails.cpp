#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define PB push_back
#define forx(i,n) for(int i=0; i<(int)n; ++i)

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m, t; cin >> x >> y >> m;
    int mx=m/x;
    int my=m/y;
    int res=0;
    for(int i=mx; i>=0; i--){
        for(int j=0; j<=my; j++){
            t=i*x+j*y;
            if (t<=m) res=max(t,res);
            else break;
        }
    }
    cout << res;
    return 0;
}