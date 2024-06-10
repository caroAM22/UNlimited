#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n;
    for(int i=0; i<n; ++i){
        cin >> k;
        if(k%2!=0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            for(int j=0; j<k/2; j++){
                if(j%2==0) cout << "LL";
                else cout << "OO";
            }
            cout << "\n";
        }
    }
    return 0;
}