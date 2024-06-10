#include <bits/stdc++.h>
using namespace std;
typedef map<string, string> ms;
typedef map<double, string> md;

string conversion(string s){
    ms hash={{"0","ce"},{"1","u"},{"2","d"},{"3","t"},{"4","c"},{"5","ci"},{"6","s"},{"7","si"},{"8","o"},{"9","n"},{"10","di"},{"11","on"},{"12","do"},{"13","tr"},{"14","ca"},{"15","q"},{".","p"}};
    string res="";
    for(char car: s){
        res+=hash[string(1, car)];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    double w;
    string v;
    md wine;

    getline(cin,v);
    for(int i=0; i<n; i++){
        getline(cin,v);
        v=v.substr(0,v.size()-1);
        w=stod(v);
        if(wine.count(w)==0){
            wine[w]=conversion(v);
        }
        cout << wine[w] << "\n";
    }
    return 0;
}