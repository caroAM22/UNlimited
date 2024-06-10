#include <bits/stdc++.h>
using namespace std;

int main(){
    string vec;
    cin >> vec;
    sort(vec.begin(), vec.end());
    int cont=0;
    vector<string> a;
    do{
        a.push_back(vec);
        cont++;
    }while(next_permutation(vec.begin(), vec.end()));
    cout << cont << "\n";
    for(auto &x: a){
        cout << x << "\n";
    }
    return 0;
}