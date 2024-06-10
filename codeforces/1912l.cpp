#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, lq, lp, op, oq; cin >> n;
    char c;
    vector<int> l(n+1,0);
    vector<int> o(n+1,0);
    for(int i=1; i<n+1; ++i){
        cin >> c;
        if(c=='L'){
            l[i]=l[i-1]+1;
            o[i]=o[i-1];
        }else{
            l[i]=l[i-1];
            o[i]=o[i-1]+1;
        }
    }  
    for(int i=1; i<n; ++i){
        lp=l[i];
        lq=l[n]-l[i];
        op=o[i];
        oq=o[n]-o[i];
        if(lp!=lq && op!=oq){
           cout << i;
           break;
        }
        if(i==n-1){
            cout << -1;
        }
    }
    return 0;
}