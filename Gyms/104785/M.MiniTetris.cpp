#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int a, b, c; cin >> a >> b >> c;
    int res=a*2;
    if(c>1){
        res+=b*2;
    }
    res+=(c/2)*3;
    cout<< res;
    return 0;
}