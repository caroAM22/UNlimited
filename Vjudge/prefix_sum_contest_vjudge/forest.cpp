#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x1, x2, y1, y2;
    cin >> n >> k;
    int f[n+1][n+1]={};
    int prefix; 
    char s;
    for(int i=1; i<n+1;++i){
        for(int j=1; j<n+1;++j){
            cin >> s;
            if(s=='*') f[i][j]=1;
        }
    }
    for(int i=1; i<n+1;++i){
        for(int j=1; j<n+1;++j){
            f[i][j]=f[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    for(int i=0; i<k;++i){
        cin >> x1 >> y1 >> x2 >> y2;
        prefix = f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1];
        cout << prefix << "\n";
    }
    return 0;
}