#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<"\n";
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
    int m, n, a, b, p; cin >> m >> n;
    mi preste, debo;
    forx(i,n){
        cin >> a >> b >> p;
        preste[a]+=p;
        debo[b]+=p;
    } 
    int t=0;
    forx(i,m){
        if(debo[i]>preste[i]){
            t++;
        }
    }
    cout << t;
    return 0;
}