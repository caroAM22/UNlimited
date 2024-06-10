#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<(int)n; ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20) << fixed;
    string cadena;
    string c="CODEFORCES";
    getline(cin,cadena);
    int n=cadena.size();
    int t=10;
    if (n>=t) {
        int i=0;
        int z=n-t;
        while (i<=t) {
            if (cadena.substr(0,i)+cadena.substr((z+i),n-1)==c) {
                cout << "YES" << endl;
                return 0;
            }
            i++;
        }
    }
    cout << "NO" << endl;
    return 0;
}