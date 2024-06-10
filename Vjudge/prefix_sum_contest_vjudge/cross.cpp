#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
	int n, k, b, signal, prefix;
    cin >> n >> k >> b;
    int s=1;
    int e=k;
    int min=k;
    int c[n+1]={}; 
    for(int i=0; i<b;++i){
		cin >> signal;
        c[signal]=1;
    }
    for(int i=1; i<n+1;++i){
        c[i]+=c[i-1];
    }
    while(e<n+1){
        prefix=c[e]-c[s-1];
        if (prefix<min) min=prefix;
        s+=1;
        e+=1;
    }
    cout << min;
    return 0;
}