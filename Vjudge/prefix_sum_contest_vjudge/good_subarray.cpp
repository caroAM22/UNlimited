#include <bits/stdc++.h>
using namespace std;

#define S second

int main() {
    int n, k, c, res;
    string num;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> k;
        cin >> num;
        int prefix[k+1];
        prefix[0]=0;
        map<int, int> d;
        d[0]=1;
        for(int j=1;j<k+1;j++){
           c=num[j-1] - '0'; 
           prefix[j]=prefix[j-1]+c;
           res=j-prefix[j];
           d[res]++;
        }
        long long cont=0;
        for (const auto& par : d) {
            if(par.S>1){
                cont+=static_cast<long long>(par.S)*(par.S-1)/2;
            };
        }
        cout << cont << "\n";
    }
    return 0;
}


