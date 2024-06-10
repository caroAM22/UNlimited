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
    int n, d, d1; cin >> n >> d;
    vi a(n);
    map<int, vi> m;
    forx(i,n){
        cin >> a[i];
    }
    vi b=a;
    sort(all(a));
    forx(i,n){
        m[a[i]].PB(i);
    }
    forx(i,n){
        int j1=0;
        forx(j,sz(m[b[i]])){
            d1=m[b[i]][j]-i;
            if(d1%d==0){
                j1=j;
                break;
            }
        }
        if(d1%d!=0){
            cout << "NO\n";
            break;
        }else{
            m[b[i]].erase(m[b[i]].begin()+j1);
            if(i==n-1){
                cout << "YES\n";
            }
        }
    }
    return 0;
}