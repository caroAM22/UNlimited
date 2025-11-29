#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
 
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
	int n, q,l,r,p; cin >> n >> q;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int s=ceil(sqrt(n));
    vector<int> b(s,INF);
    for(int i=0; i<n; i++){
        b[i/s]=min(b[i/s],v[i]);
    }
    for(int i=0; i<q; i++){
        cin >> p >> l >> r;l--; 
        if(p==2){
            r--;
            int j=l;
            int minimo=INF;
            while(j<=r){
                if(j%s==0 && j+s-1<=r){
                    minimo=min(minimo,b[j/s]);
                    j+=s;
                }else{
                    minimo=min(minimo,v[j]);
                    j++;
                }
            }
            cout << minimo << "\n";
        }else{
            v[l]=r;
            int pos=l/s;
            b[pos]=INF;
            for(int j=(l/s)*s; j<n && j<((l/s)*s)+s; j++){
                b[pos]=min(b[pos],v[j]);
            }
        }
    }
    return 0;
}