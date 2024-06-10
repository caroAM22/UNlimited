#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int total=52;
    map<char,int> m={{'A',4},{'2',4},{'3',4},{'4',4},{'5',4},{'6',4},{'7',4},{'8',4},{'9',4},{'1',4},{'J',4},{'Q',4},{'K',4}};
    string s, c;
    for(int i=0; i<n; i++){
        cin >> s;
        m[s[0]]--;
    }
    total-=n;
    cin >> n;
    total-=n;
    int j=0;
    int a=0;
    for(int i=0; i<n; i++){
        cin >> s;
        m[s[0]]--;
        if(s[0]=='K' || s[0]=='Q' || s[0]=='J' || s[0]=='1'){
            j+=10;
        }else if(s[0]=='A'){
            a++;
        }
        else if(isdigit(s[0])) {
            j += std::stoi(std::string(1, s[0]));
        }
    }
    while(a!=0){
        if(j+11<=21){
            j+=11;
        }else{
            j+=1;
        }
        a--;
    }
    int falta=21-j;
    int p=0;
    for(auto &x: m){
        if(x.first=='A' && falta==0){
            p+=x.second;
        }else if((10>falta) && (x.first=='K' || x.first=='Q' || x.first=='J' || x.first=='1')){
            p+=x.second;
        }else if(isdigit(x.first) && (stoi(string(1,x.first))>falta)){
            p+=x.second;
        }
    }
    int comun=__gcd(p, total);
    if(total/comun==1) cout << p/comun;
    else cout << p/comun << "/" << total/comun;
    return 0;
}