#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
#define forx(i,n) for(int i=1; i<(int)n; ++i)
#define all(x) x.begin(), x.end()
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout << "\n"

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, a, b, c; cin >> n;
    vi arr(n);
    forx(i,n+1) cin >> arr[i-1];
    sort(all(arr));
    ll res=0;
    forx(i,(n/3)+1){
        res+=arr[n-(2*i)];
    }
    cout << res;
    return 0;
}