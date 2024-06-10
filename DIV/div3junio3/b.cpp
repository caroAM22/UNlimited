#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int t, n, f, k, num; cin >> t;
    forx(i,t){
        cin >> n >> f >> k;
        vi v(n);
        forx(j,n) cin >> v[j];
        int fa=v[f-1];
        sort(v.rbegin(), v.rend());
        int num=0; int n1=0;
        forx(j,n){
            if(v[j]==fa && j<k) num++;
            else if(v[j]==fa && j>=k) n1++;
        }
        if(num!=0 && n1!=0) cout << "MAYBE\n";
        else if(num!=0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
