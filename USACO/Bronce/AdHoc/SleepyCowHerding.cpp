#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout << "\n"
#define all(x) x.begin(), x.end()
using ll=long long int;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<long long int> vec(3);
    for(int i=0; i<3; i++){
        cin >> vec[i];
    }
    sort(all(vec));
    ll dif=vec[1]-vec[0];
    ll dif2=vec[2]-vec[1];
    if(dif2==1 && dif==1){
        cout << 0 << "\n" << 0;
    }else if((dif2==2 && dif==2) || (dif2==2 && dif==1) || (dif2==1 && dif==2)){
        cout << 1 << "\n" << 1; 
    }else if(dif2==2 || dif==2){
        dif = max(dif,dif2)-1;
        cout << 1 << "\n" << dif; 
    }else{
        dif = max(dif,dif2)-1;
        cout << 2 << "\n" << dif; 
    }
    return 0;
}