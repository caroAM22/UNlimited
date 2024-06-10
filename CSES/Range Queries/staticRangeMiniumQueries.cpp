#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, q, a, b; cin >> n >> q;
    vi v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    vector<vi> st(n+1, vi(log2(n)+1));
    for(int i=1; i<=n; i++){
        st[i][0] = i;
    }
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i+(1<<j)-1<=n; i++){
            if(v[st[i][j-1]] < v[st[i+(1<<(j-1))][j-1]]){
                st[i][j] = st[i][j-1];
            }else{
                st[i][j] = st[i+(1<<(j-1))][j-1];
            }
        }
    }
    for(int i=0; i<q; i++){
        cin >> a >> b;
        int j = log2(b-a+1);
        cout << min(v[st[a][j]], v[st[b-(1<<j)+1][j]]) << "\n";
    }
    return 0;
}