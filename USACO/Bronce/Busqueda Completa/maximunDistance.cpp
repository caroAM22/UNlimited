#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define PB push_back
#define forx(i,n) for(int i=0; i<(int)n; ++i)

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, dis; cin >> n;
    vi x(n);
    vi y(n);
    forx(i,n) cin >> x[i];
    forx(i,n) cin >> y[i];
    int res=0;
    forx(i,n-1){
        for(int j=i+1; j<n; j++){
            dis=pow(x[j]-x[i],2)+pow(y[j]-y[i],2);
            res=max(dis,res);
        }
    }
    cout << res;
    return 0;
}