#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ll n; cin >> n;
    int i=0;
    ll k=2;
    while(k<=n){
        k *= 2;
        i++;
    }
    cout << i;
    return 0;
}