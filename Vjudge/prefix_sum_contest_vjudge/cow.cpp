#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("bcount.in", "r", stdin);
    //freopen("bcount.out", "w", stdout);
	int n, q, a, b, p, uno, dos, tres;
    cin >> n >> q;
    int prefix1[n+1]={};
    int prefix2[n+1]={};
    int prefix3[n+1]={};
    for(int i=1; i<n+1;++i){
		cin >> p;
        prefix1[i]=prefix1[i-1];
        prefix2[i]=prefix2[i-1];
        prefix3[i]=prefix3[i-1]; 
        if(p==1){
            prefix1[i]+=1;
        }else if(p==2){
            prefix2[i]+=1;
        }else if(p==3){
            prefix3[i]+=1;
        }
    }

    for(int i=0; i<q;++i){
		cin >> a >> b;
        uno = prefix1[b]-prefix1[a-1];
        dos = prefix2[b]-prefix2[a-1];
        tres = prefix3[b]-prefix3[a-1];
        cout << uno << " " << dos << " " << tres <<"\n";
    }
    return 0;
}