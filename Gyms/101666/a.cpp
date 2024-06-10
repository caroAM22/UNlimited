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
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, a; cin >> n;
    pi v;
    forx(i,n){
        cin >> a;
        v.push(a);
    }
    int u=0; int d=0;
    forx(i,n){
        if(i%2==0)u+=v.top();
        else d+=v.top();
        v.pop();
    }
    cout << u << " " << d;
    return 0;
}