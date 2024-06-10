#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using vl=vector<ll>;

ll suma;
vl a;
int n; 

ll subsets(){
    ll res=suma;
    for (int i=0; i<(1<<a.size()); ++i){  
        ll s=0;
        for (int j=0; j<a.size(); ++j){
            if (i & (1<<j)){
                s+=a[j];
            }
        }
        ll dif=abs(s-(suma-s));
        res=min(dif,res);
    }
    return res;
}


int main(){
    cin >> n;
    a.resize(n);
    suma=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        suma+=a[i];
    }
    cout << subsets();
    return 0;
}