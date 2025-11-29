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
 
vi subtrees;
vector<vi> children;
 
void dfs(int x){
    subtrees[x]=1;
    for(auto child: children[x]){
        dfs(child);
        subtrees[x]+=subtrees[child];
    }
}
 
int main(){
    int n, b; cin >> n;
    children.assign(n, vi());
    subtrees.assign(n, 0);
    forx(i,n-1){
        cin >> b; b--;
        children[b].PB(i+1);
    }
    dfs(0);
    for(auto x: subtrees){
        cout << x-1 << " ";
    }
    return 0;
}