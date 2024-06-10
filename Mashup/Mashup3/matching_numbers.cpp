#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<int> vi;
ll INFL = 1e18;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int num, n, t;
    cin >> n;
    forx(i,n){
        cin >> num;
        if (num%2 == 0){
            cout << "No" << "\n";
        }else{
            cout << "Yes" << "\n";
            forx(j,num){
                cout << j+1 << " " << (num*2)-j << "\n";
            }
        }
    }

    return 0;
}