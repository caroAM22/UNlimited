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

ii solve(set<int>& s, int r, int c){
    auto it = s.begin();
    if (r >= sz(s)) r %= sz(s);
    advance(it, r);
    int a = *it;
    
    it = s.begin();
    if (c >= sz(s)) c %= sz(s);
    advance(it, c);
    int b = *it;
    cout << a << " " << b << "\n";
    return {a, b};
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int n, r, c; cin >> n >> r >> c; r--;
    set<int> s;
    forx(i,n){
        s.insert(i+1);
    }
    set<int> contra;
    int r1=r; int c1=sz(s)-c;
    while(sz(s)>2){
        ii p=solve(s, r1, c1);
        if (p.F == p.S) {
            contra.insert(p.F);
        } else {
            s.erase(p.S);
        }
        r1+=r; c1-=c;
        s.erase(p.F);
        
        if (r1 < 0) r1 += sz(s);
        if (c1 < 0) c1 += sz(s);
    }
    for(auto& x: s){
        contra.insert(x);
    }
    for(auto& x: contra){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}