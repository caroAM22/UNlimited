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
    int n, num; cin >> n;
    multiset<int> s;
    forx(i,n){
        cin >> num; s.insert(num);
    }
    while(sz(s)>1){
        auto it=s.begin();
        int a=*it; s.erase(it);
        it=prev(s.end());
        int b=*it; s.erase(it);
        s.insert(floor((a+b)/2));
    }
    cout << *s.begin();
    return 0;
}