#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
	int n, prefixp, prefixs, prefixh, pp, ps, ph, mp, ms, mh;
    cin >> n;
    int p[n+1], s[n+1],h[n+1];
    p[0]=0;
    s[0]=0;
    h[0]=0;
    int mayor=0;
    char g;
    for(int i=1;i<n+1;++i){
        cin >> g;
        p[i]=p[i-1];
        s[i]=s[i-1];
        h[i]=h[i-1]; 
        if(g=='P'){
            s[i]+=1;
        }else if(g=='S'){
            h[i]+=1;
        }else if(g=='H'){
            p[i]+=1;
        }
    }
    for(int i=1; i<n+1; ++i){
        pp=p[i]-p[0];
        ps=s[i]-s[0];
        ph=h[i]-h[0];
        prefixp=p[n]-p[i];
        prefixs=s[n]-s[i];
        prefixh=h[n]-h[i];
        mp=max(prefixs,prefixh);
        if(pp+mp>mayor) mayor=pp+mp;
        ms=max(prefixp,prefixh);
        if(ps+ms>mayor) mayor=ps+ms;
        mh=max(prefixs,prefixp);
        if(ph+mh>mayor) mayor=ph+mh;
    }
    cout << mayor;
    return 0;
}