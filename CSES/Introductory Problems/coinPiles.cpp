#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define forx(i,n) for(int i=0; i<(int)n; ++i)

int main(){
    int n, a, b; cin >> n;
    forx(i,n){
        cin >> a >> b;
        if(a==b && a%3==0) cout << "YES";
        else if(abs(b-a)==1){
            if(a<b){
                a-=1; b-=2;
            }else{
                b-=1; a-=2;
            }

            if(a==b && a%3==0) cout <<"YES";
            else cout << "NO";
        }else cout << "NO";
        cout << "\n";
    }
    return 0;
}