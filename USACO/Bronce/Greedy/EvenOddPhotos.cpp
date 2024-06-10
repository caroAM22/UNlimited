#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a; cin >> n;
    int im=0; int pa=0;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a%2==0) pa++;
        else im++;
    } 
    
    return 0;
}