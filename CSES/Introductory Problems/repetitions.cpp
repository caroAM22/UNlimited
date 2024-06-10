#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    getline(cin, s);
    char seq=s[0];
    int maxi=0;
    int cont=0;
    for(char u: s){
        if(u==seq) cont++;
        else{
            maxi=max(cont,maxi);
            seq=u;
            cont=1;
        }
    }
    cout << max(maxi,cont);
    return 0;
}
