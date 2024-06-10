#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define all(x) x.begin(), x.end()
#define forx(i,n) for(int i=1; i<n+1; ++i)
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n";

int main(){
    int n; cin >> n;
    vector<vector<int>> v={{0,0,0}};
    forx(i,n){
        vector<int> v1=v[0];
        v1[0]=i;
        v.PB(v1);
    }
    sort(all(v));
    for(auto &x: v){
        print(x);
    }
    return 0;
}