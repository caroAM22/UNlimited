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
typedef pair<int, int> ii;
typedef vector<int> vi;


int main(){
    int n, a, x; cin >> n >> x;
    vi v;
    for(int i=0; i<n; ++i){
        cin >> a;
        v.PB(a);
    }
    sort(all(v));
    int gondolas=0;
    int i=0; int j=n-1;
    while (i<=j){
        if(i!=j && v[i]+v[j]<=x){
            i++;
            j--;
        }else{
            j--;
        }
        gondolas++;
    }
    cout << gondolas;
    return 0;
}