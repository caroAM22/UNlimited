#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int estacion=n/5;
    int sobra=n%5;
    if(sobra<=2) cout << estacion*5;
    else cout << estacion*5+5;
    return 0;
}