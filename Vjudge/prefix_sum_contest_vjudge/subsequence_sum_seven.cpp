#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n, num;
    cin >> n;
    long long s[n+1];
    long long prefix; 
    s[0]=0;
    int mayor=0;
    for(int i=1; i<n+1;++i){
		cin >> num;
        s[i]=s[i-1]+num;
    }
    int k=n;
    while(mayor==0 and k>0){
        int e=k;
        int t=1;
        while(e<n+1){
            prefix=s[e]-s[t-1];
            if (prefix%7==0){
                mayor=k;
                break;
            } 
            t+=1;
            e+=1;
        }
        k-=1;
    }
    cout << mayor;
    return 0;
}