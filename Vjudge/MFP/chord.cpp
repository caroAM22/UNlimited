#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string> se={"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    string s;
    cin >> s;
    if(se.count(s)) cout << "Yes";
    else cout << "No";
    return 0;
}