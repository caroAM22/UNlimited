#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define PB push_back

int main(){
    int n, t, a; cin >> n >> t;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    if(n==1){
        if(v[0]<=t) cout << 1;
        else cout << 0;
    }else{
        int l=0; int r=0;
        int b=0;
        int mayor=0;
        ll sum=0;
        while(r<n){
            if(v[r]+sum<=t){
                b++;
                sum+=v[r];
                r++;
            }else{
                mayor=max(b,mayor);
                b--;
                sum-=v[l];
                l++;
            }
        }
        cout << max(b,mayor);
    }
    return 0;
}