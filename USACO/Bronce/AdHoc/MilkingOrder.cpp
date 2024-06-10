#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout << "\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef priority_queue<int> pi;
typedef map<int,int> mi;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    // freopen("milkorder.in", "r", stdin);
    // freopen("milkorder.out", "w", stdout);
    int n, m, k, a, b, i, j, ant; cin >> n >> m >> k;
    vector<int> s;
    vector<int> vec(n,0);
    for(int i=0; i<m; i++){
        cin >> a;
        s.push_back(a);
    }
    for(int i=0; i<k; i++){
        cin >> a >> b;
        vec[b-1]=a;
    }
    
    return 0;
}