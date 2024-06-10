#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define forx(i,n) for(int i=0; i<(int)n; ++i)
#define S second
#define F first

int main(){
    string s; cin >> s;
    map<char,int> m;
    for(char &c: s){
        m[c]++;
    }
    int cont=0;
    char me='\0';
    for(auto &x: m){
        if(x.S%2!=0){
            cont++;
            me=x.F;
            m[me]--;
        }
        if(cont>1) break;
    }
    if(cont>1) cout << "NO SOLUTION";
    else{
        string mi="", mi2;
        for(auto &x: m){
            forx(i,(x.S/2)){
                mi+=x.F;
            }
        }
        mi2=mi;
        reverse(all(mi));
        if(me!='\0') mi2+=me;
        cout << mi2+mi;
    }
    return 0;
}