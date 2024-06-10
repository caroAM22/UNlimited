#include <bits/stdc++.h>
using namespace std;
typedef map<int, int> mp;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, m, k, c, p, res; 
    cin >> n >> m >> k;
    mp target;
    mp cobro;
    for(int i=0; i<k; i++){
        cin >> p >> c; 
        if(target.count(c)>0){
            res=abs(target[c]-p);
            if(res==0){
                cobro[c]+=100;
            }else{
                cobro[c]+=res;
            }
            target.erase(c);
        }else{
            target.insert({c, p});
        }
    }
    for(int i=1; i<m+1; i++){
        if(cobro.count(i)>0 && target.count(i)==0){
            cout << " " << cobro[i];
        }
        else if(target.count(i)>0){
            cout << " " << cobro[i]+100;
        }else{
            cout << " " << 0;
        }
    }
    return 0;
}