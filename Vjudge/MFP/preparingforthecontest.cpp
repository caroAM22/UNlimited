#include <bits/stdc++.h>
using namespace std;

#define PB push_back
typedef vector<int> vi;

int main(){
    int n, c, k; cin >> n;
    for(int i=0; i<n; ++i){
        cin >> c >> k;
        vi l1;
        for(int j=(c-k);j>0; --j){
            cout << j << " ";
        }
        for(int j=(c-k)+1;j<=c; ++j){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
