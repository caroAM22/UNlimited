#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    long long int cont=0;
    long long int a, b;
    cin >> a;
    for(int i=0; i<n-1; i++){
        cin >> b;
        if(b<a){
            cont=cont+(a-b);
            b=a;
        }
        a=b;
    }
    cout << cont;
    return 0;
}